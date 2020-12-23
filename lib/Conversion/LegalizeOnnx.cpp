//===------------------------------------------------------------*- C++ -*-===//
//
//===----------------------------------------------------------------------===//

#include "Conversion/Passes.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/IR/Builders.h"

using namespace std;
using namespace mlir;
using namespace scalehls;

namespace {
struct LegalizeOnnx : public LegalizeOnnxBase<LegalizeOnnx> {
  void runOnOperation() override;
};
} // namespace

void LegalizeOnnx::runOnOperation() {
  auto module = getOperation();
  auto builder = OpBuilder(module);

  StringRef weightFileName = "";
  int64_t weightSizeInBytes = 0;
  int64_t numInputs = 0;
  int64_t numOutputs = 0;
  StringRef topFunction = "";

  SmallVector<FuncOp, 2> funcs;
  SmallVector<Operation *, 16> opsToErase;

  for (auto &op : module) {
    if (op.getName().getStringRef() == "krnl.packed_const") {
      // Fetch weight information and erase packed_const operation.
      weightFileName = op.getAttrOfType<StringAttr>("file_name").getValue();
      weightSizeInBytes =
          op.getAttrOfType<IntegerAttr>("size_in_bytes").getInt();
      opsToErase.push_back(&op);

    } else if (op.getName().getStringRef() == "krnl.entry_point") {
      // Fetch top function information and erase entry_point operation.
      topFunction = op.getAttrOfType<FlatSymbolRefAttr>("func").getValue();
      numInputs = op.getAttrOfType<IntegerAttr>("numInputs").getInt();
      numOutputs = op.getAttrOfType<IntegerAttr>("numOutputs").getInt();
      opsToErase.push_back(&op);

    } else if (auto func = dyn_cast<FuncOp>(op))
      funcs.push_back(func);
  }

  for (auto func : funcs) {
    SmallVector<Type, 16> weightTypes;
    SmallVector<int64_t, 16> weightOffsets;
    SmallVector<Value, 16> weightValues;
    for (auto &op : func.front()) {
      if (op.getName().getStringRef() == "krnl.global") {
        if (auto value = op.getAttrOfType<DenseFPElementsAttr>("value")) {
          // If the kernel global operation gets a value, create a standard
          // constant operation to substitute it.
          builder.setInsertionPoint(&op);
          auto tensor = builder.create<mlir::ConstantOp>(op.getLoc(), value);
          auto memref = builder.create<mlir::TensorToMemrefOp>(
              op.getLoc(), op.getResult(0).getType(), tensor);
          op.getResult(0).replaceAllUsesWith(memref);

        } else {
          // If value attribute doesn't exist, record the type and offset.
          weightTypes.push_back(op.getResult(0).getType());
          weightOffsets.push_back(
              op.getAttrOfType<IntegerAttr>("offset").getInt());
          weightValues.push_back(op.getResult(0));
        }
        // Erase the kernel global operation.
        opsToErase.push_back(&op);

      } else if (op.getName().getStringRef() == "krnl.memcpy") {
        // Replace kernel memcpy with standard memref reshape operation.
        auto result = op.getOperand(1);
        builder.setInsertionPointAfterValue(result);
        auto resultRank = result.getType().cast<MemRefType>().getRank();
        auto shape = builder.create<mlir::AllocOp>(
            op.getLoc(), MemRefType::get(resultRank, builder.getIndexType()));
        auto newResult = builder.create<mlir::MemRefReshapeOp>(
            op.getLoc(), result.getType(), op.getOperand(0), shape);

        result.replaceAllUsesWith(newResult);
        opsToErase.push_back(&op);

      } else if (isa<mlir::DeallocOp>(op))
        opsToErase.push_back(&op);
    }

    // Construct new function type.
    SmallVector<Type, 16> inputTypes(func.getArgumentTypes());
    inputTypes.append(weightTypes.begin(), weightTypes.end());
    auto newType = FunctionType::get(inputTypes, func.getType().getResults(),
                                     func.getContext());

    // Record the argument number of the old function.
    auto oldArgNum = func.getNumArguments();

    // Set function type to newType.
    func.setType(newType);

    // Add new arguments to the entry block.
    func.front().addArguments(weightTypes);

    // Replace all uses of the kernel global operation with corresponding entry
    // block argument.
    SmallVector<int64_t, 16> weightIndex;
    for (unsigned i = 0, e = weightOffsets.size(); i < e; ++i) {
      weightValues[i].replaceAllUsesWith(
          func.front().getArgument(i + oldArgNum));
      weightIndex.push_back(i + oldArgNum);
    }

    // Set weight offset and index attribute.
    func.setAttr("weight_offsets", builder.getI64ArrayAttr(weightOffsets));
    func.setAttr("weight_index", builder.getI64ArrayAttr(weightIndex));

    // Set other function attributes if the current function is top function.
    if (func.getName() == topFunction) {
      func.setAttr("top_function", builder.getBoolAttr(true));
      func.setAttr("weight_file_name", builder.getStringAttr(weightFileName));
      func.setAttr("weight_size_in_bytes",
                   builder.getI64IntegerAttr(weightSizeInBytes));
      func.setAttr("inputs_num", builder.getI64IntegerAttr(numInputs));
      func.setAttr("outputs_num", builder.getI64IntegerAttr(numOutputs));
    }
  }

  // Erase all operations marked as erase.
  for (auto op : opsToErase)
    op->erase();
}

std::unique_ptr<mlir::Pass> scalehls::createLegalizeOnnxPass() {
  return std::make_unique<LegalizeOnnx>();
}
