
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//



/// This is top function.
void syr2k_32(
  float v0,
  float v1,
  float v2[32][32],
  float v3[32][32],
  float v4[32][32]
) {	// L3




  loop0: for (int v5 = 0; v5 < 32; v5 += 1) {	// L9
    loop1: for (int v6 = 0; v6 < 32; v6 += 1) {	// L4
      loop2: for (int v7 = 0; v7 < 32; v7 += 1) {	// L5
        if ((v6 - v7) >= 0) {	// L5
          float v8 = v2[v6][v7];	// L6
          float v9 = v8 * v1;	// L7
          if (v5 == 0) {	// L5
            v2[v6][v7] = v9;	// L8
          }
          float v10 = v3[v6][v5];	// L10
          float v11 = v4[v7][v5];	// L11
          float v12 = v10 * v11;	// L12
          float v13 = v4[v6][v5];	// L13
          float v14 = v3[v7][v5];	// L14
          float v15 = v13 * v14;	// L15
          float v16 = v12 + v15;	// L16
          float v17 = v0 * v16;	// L17
          float v18 = v2[v6][v7];	// L18
          float v19 = v18 + v17;	// L19
          v2[v6][v7] = v19;	// L20
        }
      }
    }
  }
}

