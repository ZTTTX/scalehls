//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The ScaleHLS Authors.
//
//===----------------------------------------------------------------------===//

#ifndef SCALEHLS_ANALYSIS_QORESTIMATION_H
#define SCALEHLS_ANALYSIS_QORESTIMATION_H

#include "external/INIReader.h"
#include "mlir/Analysis/AffineAnalysis.h"
#include "mlir/IR/BuiltinOps.h"
#include "scalehls/Analysis/Utils.h"
#include "scalehls/Dialect/HLSCpp/Visitor.h"

namespace mlir {
namespace scalehls {

/// For storing all resource types.
struct Resource {
  int64_t bram = 0;
  int64_t dsp = 0;
  int64_t ff = 0;
  int64_t lut = 0;

  Resource(int64_t bram, int64_t dsp, int64_t ff, int64_t lut)
      : bram(bram), dsp(dsp), ff(ff), lut(lut) {}
  Resource() {}
};

using LatencyMap = llvm::StringMap<int64_t>;
void getLatencyMap(INIReader spec, LatencyMap &latencyMap);

class HLSCppEstimator
    : public HLSCppVisitorBase<HLSCppEstimator, bool, int64_t>,
      public HLSCppAnalysisBase {
public:
  explicit HLSCppEstimator(OpBuilder &builder, LatencyMap &latencyMap)
      : HLSCppAnalysisBase(builder), latencyMap(latencyMap) {}

  // For storing all dependencies indexed by the dependency source operation.
  using Depends = SmallVector<Operation *, 16>;
  using DependsMap = DenseMap<Operation *, Depends>;

  // Hold the memory ports information.
  struct MemPortInfo {
    unsigned rdPort = 0;
    unsigned wrPort = 0;
    unsigned rdwrPort = 0;

    SmallVector<MemRefAccess, 2> rdAccesses;
  };

  // For storing memory port information of all partitions indexed by the
  // {schedule_level, memref}.
  using MemPortInfos = std::vector<MemPortInfo>;
  using MemPortInfosMap = DenseMap<int64_t, DenseMap<Value, MemPortInfos>>;

  // For storing the DSP resource utilization indexed by the schedule level.
  using ResourceMap = DenseMap<int64_t, int64_t>;

  /// Collect all dependencies detected in the function.
  void getFuncDependencies();

  void setResourceValue(Operation *op, Resource resource) {
    setAttrValue(op, "bram", resource.bram);
    setAttrValue(op, "dsp", resource.dsp);
    setAttrValue(op, "ff", resource.ff);
    setAttrValue(op, "lut", resource.lut);
  }

  void setScheduleValue(Operation *op, int64_t begin, int64_t end) {
    setAttrValue(op, "schedule_begin", begin);
    setAttrValue(op, "schedule_end", end);
  }

  using HLSCppVisitorBase::visitOp;
  bool visitUnhandledOp(Operation *op, int64_t begin) {
    // Default latency of any unhandled operation is 0.
    return setScheduleValue(op, begin, begin), true;
  }

  /// LoadOp and StoreOp related methods.
  void getPartitionIndices(Operation *op);
  void estimateLoadStore(Operation *op, int64_t begin);
  bool visitOp(AffineLoadOp op, int64_t begin) {
    return estimateLoadStore(op, begin), true;
  }
  bool visitOp(AffineStoreOp op, int64_t begin) {
    return estimateLoadStore(op, begin), true;
  }
  bool visitOp(LoadOp op, int64_t begin) {
    return setScheduleValue(op, begin, begin + 2), true;
  }
  bool visitOp(StoreOp op, int64_t begin) {
    return setScheduleValue(op, begin, begin + 1), true;
  }

  /// AffineForOp related methods.
  int64_t getResMinII(int64_t begin, int64_t end, MemAccessesMap &map);
  int64_t getDepMinII(int64_t II, FuncOp func, MemAccessesMap &map);
  int64_t getDepMinII(int64_t II, AffineForOp forOp, MemAccessesMap &map);
  bool visitOp(AffineForOp op, int64_t begin);

  /// Other operation handlers.
  bool visitOp(AffineIfOp op, int64_t begin);
  bool visitOp(CallOp op, int64_t begin);

  /// Handle operations with profiled latency.
#define HANDLE(OPTYPE, KEYNAME)                                                \
  bool visitOp(OPTYPE op, int64_t begin) {                                     \
    setScheduleValue(op, begin, begin + latencyMap[KEYNAME] + 1);              \
    return true;                                                               \
  }
  HANDLE(AddFOp, "fadd");
  HANDLE(SubFOp, "fadd");
  HANDLE(MulFOp, "fmul");
  HANDLE(DivFOp, "fdiv");
  HANDLE(CmpFOp, "fcmp");
#undef HANDLE

  /// Block scheduler and estimator.
  int64_t getDSPMap(Block &block, ResourceMap &faddMap, ResourceMap &fmulMap);
  Resource estimateResource(Block &block, int64_t interval = -1);
  Optional<std::pair<int64_t, int64_t>> estimateBlock(Block &block,
                                                      int64_t begin);
  void reverseSchedule(Block &block);

  /// Estimator entries.
  void estimateFunc(FuncOp &func);
  void estimateLoop(AffineForOp &loop);

  DependsMap dependsMap;
  MemPortInfosMap memPortInfosMap;
  LatencyMap &latencyMap;
};

} // namespace scalehls
} // namespace mlir

#endif // SCALEHLS_ANALYSIS_QORESTIMATION_H
