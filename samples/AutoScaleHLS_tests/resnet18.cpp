
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>

using namespace std;

/// This is top function.
void main_graph(
  float v0[1][3][32][32],
  float v1[64][3][3][3],
  float v2[64][64][3][3],
  float v3[64][64][3][3],
  float v4[64][64][3][3],
  float v5[64][64][3][3],
  float v6[128][64][3][3],
  float v7[128][128][3][3],
  float v8[128][64][1][1],
  float v9[128][128][3][3],
  float v10[128][128][3][3],
  float v11[256][128][3][3],
  float v12[256][256][3][3],
  float v13[256][128][1][1],
  float v14[256][256][3][3],
  float v15[256][256][3][3],
  float v16[512][256][3][3],
  float v17[512][512][3][3],
  float v18[512][256][1][1],
  float v19[512][512][3][3],
  float v20[512][512][3][3],
  float v21[10][512],
  float v22[1][10]
) {	// L8
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=v0
  #pragma HLS interface bram port=v1
  #pragma HLS interface bram port=v2
  #pragma HLS interface bram port=v3
  #pragma HLS interface bram port=v4
  #pragma HLS interface bram port=v5
  #pragma HLS interface bram port=v6
  #pragma HLS interface bram port=v7
  #pragma HLS interface bram port=v8
  #pragma HLS interface bram port=v9
  #pragma HLS interface bram port=v10
  #pragma HLS interface bram port=v11
  #pragma HLS interface bram port=v12
  #pragma HLS interface bram port=v13
  #pragma HLS interface bram port=v14
  #pragma HLS interface bram port=v15
  #pragma HLS interface bram port=v16
  #pragma HLS interface bram port=v17
  #pragma HLS interface bram port=v18
  #pragma HLS interface bram port=v19
  #pragma HLS interface bram port=v20
  #pragma HLS interface bram port=v21
  #pragma HLS interface bram port=v22

  #pragma HLS resource variable=v0 core=ram_s2p_bram

  #pragma HLS resource variable=v1 core=ram_s2p_bram

  #pragma HLS resource variable=v2 core=ram_s2p_bram

  #pragma HLS resource variable=v3 core=ram_s2p_bram

  #pragma HLS resource variable=v4 core=ram_s2p_bram

  #pragma HLS resource variable=v5 core=ram_s2p_bram

  #pragma HLS resource variable=v6 core=ram_s2p_bram

  #pragma HLS resource variable=v7 core=ram_s2p_bram

  #pragma HLS resource variable=v8 core=ram_s2p_bram

  #pragma HLS resource variable=v9 core=ram_s2p_bram

  #pragma HLS resource variable=v10 core=ram_s2p_bram

  #pragma HLS resource variable=v11 core=ram_s2p_bram

  #pragma HLS resource variable=v12 core=ram_s2p_bram

  #pragma HLS resource variable=v13 core=ram_s2p_bram

  #pragma HLS resource variable=v14 core=ram_s2p_bram

  #pragma HLS resource variable=v15 core=ram_s2p_bram

  #pragma HLS resource variable=v16 core=ram_s2p_bram

  #pragma HLS resource variable=v17 core=ram_s2p_bram

  #pragma HLS resource variable=v18 core=ram_s2p_bram

  #pragma HLS resource variable=v19 core=ram_s2p_bram

  #pragma HLS resource variable=v20 core=ram_s2p_bram

  #pragma HLS resource variable=v21 core=ram_s2p_bram

  #pragma HLS resource variable=v22 core=ram_s2p_bram

  float v23[10] = {-2.781226e-02, -4.107117e-02, -8.704335e-03, -3.831929e-02, -2.075570e-02, 4.087221e-02, 3.640073e-02, 4.095368e-02, 3.038846e-03, -4.327787e-02};	// L12
  float v24[1][512];	// L14
  #pragma HLS resource variable=v24 core=ram_s2p_bram

  float v25[1][512][1][1];	// L15
  #pragma HLS resource variable=v25 core=ram_s2p_bram

  float v26[1][512][4][4];	// L16
  #pragma HLS resource variable=v26 core=ram_s2p_bram

  float v27[1][512][4][4];	// L17
  #pragma HLS resource variable=v27 core=ram_s2p_bram

  float v28[1][512][4][4];	// L18
  #pragma HLS resource variable=v28 core=ram_s2p_bram

  float v29[1][512][6][6];	// L19
  #pragma HLS resource variable=v29 core=ram_s2p_bram

  float v30[1][512][4][4];	// L20
  #pragma HLS resource variable=v30 core=ram_s2p_bram

  float v31[1][512][4][4];	// L21
  #pragma HLS resource variable=v31 core=ram_s2p_bram

  float v32[1][512][6][6];	// L22
  #pragma HLS resource variable=v32 core=ram_s2p_bram

  float v33[1][512][4][4];	// L23
  #pragma HLS resource variable=v33 core=ram_s2p_bram

  float v34[1][512][4][4];	// L24
  #pragma HLS resource variable=v34 core=ram_s2p_bram

  float v35[1][512][4][4];	// L25
  #pragma HLS resource variable=v35 core=ram_s2p_bram

  float v36[1][512][4][4];	// L26
  #pragma HLS resource variable=v36 core=ram_s2p_bram

  float v37[1][512][6][6];	// L27
  #pragma HLS resource variable=v37 core=ram_s2p_bram

  float v38[1][512][4][4];	// L28
  #pragma HLS resource variable=v38 core=ram_s2p_bram

  float v39[1][512][4][4];	// L29
  #pragma HLS resource variable=v39 core=ram_s2p_bram

  float v40[1][256][10][10];	// L30
  #pragma HLS resource variable=v40 core=ram_s2p_bram

  float v41[1][256][8][8];	// L31
  #pragma HLS resource variable=v41 core=ram_s2p_bram

  float v42[1][256][8][8];	// L32
  #pragma HLS resource variable=v42 core=ram_s2p_bram

  float v43[1][256][8][8];	// L33
  #pragma HLS resource variable=v43 core=ram_s2p_bram

  float v44[1][256][10][10];	// L34
  #pragma HLS resource variable=v44 core=ram_s2p_bram

  float v45[1][256][8][8];	// L35
  #pragma HLS resource variable=v45 core=ram_s2p_bram

  float v46[1][256][8][8];	// L36
  #pragma HLS resource variable=v46 core=ram_s2p_bram

  float v47[1][256][10][10];	// L37
  #pragma HLS resource variable=v47 core=ram_s2p_bram

  float v48[1][256][8][8];	// L38
  #pragma HLS resource variable=v48 core=ram_s2p_bram

  float v49[1][256][8][8];	// L39
  #pragma HLS resource variable=v49 core=ram_s2p_bram

  float v50[1][256][8][8];	// L40
  #pragma HLS resource variable=v50 core=ram_s2p_bram

  float v51[1][256][8][8];	// L41
  #pragma HLS resource variable=v51 core=ram_s2p_bram

  float v52[1][256][10][10];	// L42
  #pragma HLS resource variable=v52 core=ram_s2p_bram

  float v53[1][256][8][8];	// L43
  #pragma HLS resource variable=v53 core=ram_s2p_bram

  float v54[1][256][8][8];	// L44
  #pragma HLS resource variable=v54 core=ram_s2p_bram

  float v55[1][128][18][18];	// L45
  #pragma HLS resource variable=v55 core=ram_s2p_bram

  float v56[1][128][16][16];	// L46
  #pragma HLS resource variable=v56 core=ram_s2p_bram

  float v57[1][128][16][16];	// L47
  #pragma HLS resource variable=v57 core=ram_s2p_bram

  float v58[1][128][16][16];	// L48
  #pragma HLS resource variable=v58 core=ram_s2p_bram

  float v59[1][128][18][18];	// L49
  #pragma HLS resource variable=v59 core=ram_s2p_bram

  float v60[1][128][16][16];	// L50
  #pragma HLS resource variable=v60 core=ram_s2p_bram

  float v61[1][128][16][16];	// L51
  #pragma HLS resource variable=v61 core=ram_s2p_bram

  float v62[1][128][18][18];	// L52
  #pragma HLS resource variable=v62 core=ram_s2p_bram

  float v63[1][128][16][16];	// L53
  #pragma HLS resource variable=v63 core=ram_s2p_bram

  float v64[1][128][16][16];	// L54
  #pragma HLS resource variable=v64 core=ram_s2p_bram

  float v65[1][128][16][16];	// L55
  #pragma HLS resource variable=v65 core=ram_s2p_bram

  float v66[1][128][16][16];	// L56
  #pragma HLS resource variable=v66 core=ram_s2p_bram

  float v67[1][128][18][18];	// L57
  #pragma HLS resource variable=v67 core=ram_s2p_bram

  float v68[1][128][16][16];	// L58
  #pragma HLS resource variable=v68 core=ram_s2p_bram

  float v69[1][128][16][16];	// L59
  #pragma HLS resource variable=v69 core=ram_s2p_bram

  float v70[1][64][34][34];	// L60
  #pragma HLS resource variable=v70 core=ram_s2p_bram

  float v71[1][64][32][32];	// L61
  #pragma HLS resource variable=v71 core=ram_s2p_bram

  float v72[1][64][32][32];	// L62
  #pragma HLS resource variable=v72 core=ram_s2p_bram

  float v73[1][64][32][32];	// L63
  #pragma HLS resource variable=v73 core=ram_s2p_bram

  float v74[1][64][34][34];	// L64
  #pragma HLS resource variable=v74 core=ram_s2p_bram

  float v75[1][64][32][32];	// L65
  #pragma HLS resource variable=v75 core=ram_s2p_bram

  float v76[1][64][32][32];	// L66
  #pragma HLS resource variable=v76 core=ram_s2p_bram

  float v77[1][64][34][34];	// L67
  #pragma HLS resource variable=v77 core=ram_s2p_bram

  float v78[1][64][32][32];	// L68
  #pragma HLS resource variable=v78 core=ram_s2p_bram

  float v79[1][64][32][32];	// L69
  #pragma HLS resource variable=v79 core=ram_s2p_bram

  float v80[1][64][32][32];	// L70
  #pragma HLS resource variable=v80 core=ram_s2p_bram

  float v81[1][64][34][34];	// L71
  #pragma HLS resource variable=v81 core=ram_s2p_bram

  float v82[1][64][32][32];	// L72
  #pragma HLS resource variable=v82 core=ram_s2p_bram

  float v83[1][64][32][32];	// L73
  #pragma HLS resource variable=v83 core=ram_s2p_bram

  float v84[1][64][34][34];	// L74
  #pragma HLS resource variable=v84 core=ram_s2p_bram

  float v85[1][64][32][32];	// L75
  #pragma HLS resource variable=v85 core=ram_s2p_bram

  float v86[1][64][32][32];	// L76
  #pragma HLS resource variable=v86 core=ram_s2p_bram

  float v87[1][3][34][34];	// L77
  #pragma HLS resource variable=v87 core=ram_s2p_bram

  for (int v88 = 0; v88 < 3; v88 += 1) {	// L78
    for (int v89 = 0; v89 < 34; v89 += 1) {	// L79
      for (int v90 = 0; v90 < 34; v90 += 1) {	// L80
        v87[0][v88][v89][v90] = 0.000000;	// L81
      }
    }
  }
  for (int v91 = 0; v91 < 3; v91 += 1) {	// L85
    for (int v92 = 0; v92 < 32; v92 += 1) {	// L86
      for (int v93 = 0; v93 < 32; v93 += 1) {	// L87
        float v94 = v0[0][v91][v92][v93];	// L88
        v87[0][v91][(v92 + 1)][(v93 + 1)] = v94;	// L89
      }
    }
  }
  for (int v95 = 0; v95 < 3; v95 += 1) {	// L93
    for (int v96 = 0; v96 < 3; v96 += 1) {	// L94
      for (int v97 = 0; v97 < 3; v97 += 1) {	// L95
        for (int v98 = 0; v98 < 64; v98 += 1) {	// L96
          for (int v99 = 0; v99 < 32; v99 += 1) {	// L97
            for (int v100 = 0; v100 < 32; v100 += 1) {	// L98
              float v101 = v87[0][v95][(v99 + v96)][(v100 + v97)];	// L99
              float v102 = v1[v98][v95][v96][v97];	// L100
              float v103 = v86[0][v98][v99][v100];	// L101
              float v104;
              if (v95 == 0 && v96 == 0 && v97 == 0) {	// L102
                v104 = 0.000000;	// L103
              } else {
                v104 = v103;	// L105
              }
              float v105 = v101 * v102;	// L107
              float v106 = v104 + v105;	// L108
              v86[0][v98][v99][v100] = v106;	// L109
            }
          }
        }
      }
    }
  }
  for (int v107 = 0; v107 < 64; v107 += 1) {	// L116
    for (int v108 = 0; v108 < 32; v108 += 1) {	// L117
      for (int v109 = 0; v109 < 32; v109 += 1) {	// L118
        float v110 = v86[0][v107][v108][v109];	// L119
        bool v111 = v110 < 0.000000;	// L120
        float v112 = v111 ? (float)0.000000 : (float)v110;	// L121
        v85[0][v107][v108][v109] = v112;	// L122
      }
    }
  }
  for (int v113 = 0; v113 < 64; v113 += 1) {	// L126
    for (int v114 = 0; v114 < 34; v114 += 1) {	// L127
      for (int v115 = 0; v115 < 34; v115 += 1) {	// L128
        v84[0][v113][v114][v115] = 0.000000;	// L129
      }
    }
  }
  for (int v116 = 0; v116 < 64; v116 += 1) {	// L133
    for (int v117 = 0; v117 < 32; v117 += 1) {	// L134
      for (int v118 = 0; v118 < 32; v118 += 1) {	// L135
        float v119 = v85[0][v116][v117][v118];	// L136
        v84[0][v116][(v117 + 1)][(v118 + 1)] = v119;	// L137
      }
    }
  }
  for (int v120 = 0; v120 < 64; v120 += 1) {	// L141
    for (int v121 = 0; v121 < 3; v121 += 1) {	// L142
      for (int v122 = 0; v122 < 3; v122 += 1) {	// L143
        for (int v123 = 0; v123 < 64; v123 += 1) {	// L144
          for (int v124 = 0; v124 < 32; v124 += 1) {	// L145
            for (int v125 = 0; v125 < 32; v125 += 1) {	// L146
              float v126 = v84[0][v120][(v124 + v121)][(v125 + v122)];	// L147
              float v127 = v2[v123][v120][v121][v122];	// L148
              float v128 = v83[0][v123][v124][v125];	// L149
              float v129;
              if (v120 == 0 && v121 == 0 && v122 == 0) {	// L150
                v129 = 0.000000;	// L151
              } else {
                v129 = v128;	// L153
              }
              float v130 = v126 * v127;	// L155
              float v131 = v129 + v130;	// L156
              v83[0][v123][v124][v125] = v131;	// L157
            }
          }
        }
      }
    }
  }
  for (int v132 = 0; v132 < 64; v132 += 1) {	// L164
    for (int v133 = 0; v133 < 32; v133 += 1) {	// L165
      for (int v134 = 0; v134 < 32; v134 += 1) {	// L166
        float v135 = v83[0][v132][v133][v134];	// L167
        bool v136 = v135 < 0.000000;	// L168
        float v137 = v136 ? (float)0.000000 : (float)v135;	// L169
        v82[0][v132][v133][v134] = v137;	// L170
      }
    }
  }
  for (int v138 = 0; v138 < 64; v138 += 1) {	// L174
    for (int v139 = 0; v139 < 34; v139 += 1) {	// L175
      for (int v140 = 0; v140 < 34; v140 += 1) {	// L176
        v81[0][v138][v139][v140] = 0.000000;	// L177
      }
    }
  }
  for (int v141 = 0; v141 < 64; v141 += 1) {	// L181
    for (int v142 = 0; v142 < 32; v142 += 1) {	// L182
      for (int v143 = 0; v143 < 32; v143 += 1) {	// L183
        float v144 = v82[0][v141][v142][v143];	// L184
        v81[0][v141][(v142 + 1)][(v143 + 1)] = v144;	// L185
      }
    }
  }
  for (int v145 = 0; v145 < 64; v145 += 1) {	// L189
    for (int v146 = 0; v146 < 3; v146 += 1) {	// L190
      for (int v147 = 0; v147 < 3; v147 += 1) {	// L191
        for (int v148 = 0; v148 < 64; v148 += 1) {	// L192
          for (int v149 = 0; v149 < 32; v149 += 1) {	// L193
            for (int v150 = 0; v150 < 32; v150 += 1) {	// L194
              float v151 = v81[0][v145][(v149 + v146)][(v150 + v147)];	// L195
              float v152 = v3[v148][v145][v146][v147];	// L196
              float v153 = v80[0][v148][v149][v150];	// L197
              float v154;
              if (v145 == 0 && v146 == 0 && v147 == 0) {	// L198
                v154 = 0.000000;	// L199
              } else {
                v154 = v153;	// L201
              }
              float v155 = v151 * v152;	// L203
              float v156 = v154 + v155;	// L204
              v80[0][v148][v149][v150] = v156;	// L205
            }
          }
        }
      }
    }
  }
  for (int v157 = 0; v157 < 64; v157 += 1) {	// L212
    for (int v158 = 0; v158 < 32; v158 += 1) {	// L213
      for (int v159 = 0; v159 < 32; v159 += 1) {	// L214
        float v160 = v80[0][v157][v158][v159];	// L215
        float v161 = v85[0][v157][v158][v159];	// L216
        float v162 = v160 + v161;	// L217
        v79[0][v157][v158][v159] = v162;	// L218
      }
    }
  }
  for (int v163 = 0; v163 < 64; v163 += 1) {	// L222
    for (int v164 = 0; v164 < 32; v164 += 1) {	// L223
      for (int v165 = 0; v165 < 32; v165 += 1) {	// L224
        float v166 = v79[0][v163][v164][v165];	// L225
        bool v167 = v166 < 0.000000;	// L226
        float v168 = v167 ? (float)0.000000 : (float)v166;	// L227
        v78[0][v163][v164][v165] = v168;	// L228
      }
    }
  }
  for (int v169 = 0; v169 < 64; v169 += 1) {	// L232
    for (int v170 = 0; v170 < 34; v170 += 1) {	// L233
      for (int v171 = 0; v171 < 34; v171 += 1) {	// L234
        v77[0][v169][v170][v171] = 0.000000;	// L235
      }
    }
  }
  for (int v172 = 0; v172 < 64; v172 += 1) {	// L239
    for (int v173 = 0; v173 < 32; v173 += 1) {	// L240
      for (int v174 = 0; v174 < 32; v174 += 1) {	// L241
        float v175 = v78[0][v172][v173][v174];	// L242
        v77[0][v172][(v173 + 1)][(v174 + 1)] = v175;	// L243
      }
    }
  }
  for (int v176 = 0; v176 < 64; v176 += 1) {	// L247
    for (int v177 = 0; v177 < 3; v177 += 1) {	// L248
      for (int v178 = 0; v178 < 3; v178 += 1) {	// L249
        for (int v179 = 0; v179 < 64; v179 += 1) {	// L250
          for (int v180 = 0; v180 < 32; v180 += 1) {	// L251
            for (int v181 = 0; v181 < 32; v181 += 1) {	// L252
              float v182 = v77[0][v176][(v180 + v177)][(v181 + v178)];	// L253
              float v183 = v4[v179][v176][v177][v178];	// L254
              float v184 = v76[0][v179][v180][v181];	// L255
              float v185;
              if (v176 == 0 && v177 == 0 && v178 == 0) {	// L256
                v185 = 0.000000;	// L257
              } else {
                v185 = v184;	// L259
              }
              float v186 = v182 * v183;	// L261
              float v187 = v185 + v186;	// L262
              v76[0][v179][v180][v181] = v187;	// L263
            }
          }
        }
      }
    }
  }
  for (int v188 = 0; v188 < 64; v188 += 1) {	// L270
    for (int v189 = 0; v189 < 32; v189 += 1) {	// L271
      for (int v190 = 0; v190 < 32; v190 += 1) {	// L272
        float v191 = v76[0][v188][v189][v190];	// L273
        bool v192 = v191 < 0.000000;	// L274
        float v193 = v192 ? (float)0.000000 : (float)v191;	// L275
        v75[0][v188][v189][v190] = v193;	// L276
      }
    }
  }
  for (int v194 = 0; v194 < 64; v194 += 1) {	// L280
    for (int v195 = 0; v195 < 34; v195 += 1) {	// L281
      for (int v196 = 0; v196 < 34; v196 += 1) {	// L282
        v74[0][v194][v195][v196] = 0.000000;	// L283
      }
    }
  }
  for (int v197 = 0; v197 < 64; v197 += 1) {	// L287
    for (int v198 = 0; v198 < 32; v198 += 1) {	// L288
      for (int v199 = 0; v199 < 32; v199 += 1) {	// L289
        float v200 = v75[0][v197][v198][v199];	// L290
        v74[0][v197][(v198 + 1)][(v199 + 1)] = v200;	// L291
      }
    }
  }
  for (int v201 = 0; v201 < 64; v201 += 1) {	// L295
    for (int v202 = 0; v202 < 3; v202 += 1) {	// L296
      for (int v203 = 0; v203 < 3; v203 += 1) {	// L297
        for (int v204 = 0; v204 < 64; v204 += 1) {	// L298
          for (int v205 = 0; v205 < 32; v205 += 1) {	// L299
            for (int v206 = 0; v206 < 32; v206 += 1) {	// L300
              float v207 = v74[0][v201][(v205 + v202)][(v206 + v203)];	// L301
              float v208 = v5[v204][v201][v202][v203];	// L302
              float v209 = v73[0][v204][v205][v206];	// L303
              float v210;
              if (v201 == 0 && v202 == 0 && v203 == 0) {	// L304
                v210 = 0.000000;	// L305
              } else {
                v210 = v209;	// L307
              }
              float v211 = v207 * v208;	// L309
              float v212 = v210 + v211;	// L310
              v73[0][v204][v205][v206] = v212;	// L311
            }
          }
        }
      }
    }
  }
  for (int v213 = 0; v213 < 64; v213 += 1) {	// L318
    for (int v214 = 0; v214 < 32; v214 += 1) {	// L319
      for (int v215 = 0; v215 < 32; v215 += 1) {	// L320
        float v216 = v73[0][v213][v214][v215];	// L321
        float v217 = v78[0][v213][v214][v215];	// L322
        float v218 = v216 + v217;	// L323
        v72[0][v213][v214][v215] = v218;	// L324
      }
    }
  }
  for (int v219 = 0; v219 < 64; v219 += 1) {	// L328
    for (int v220 = 0; v220 < 32; v220 += 1) {	// L329
      for (int v221 = 0; v221 < 32; v221 += 1) {	// L330
        float v222 = v72[0][v219][v220][v221];	// L331
        bool v223 = v222 < 0.000000;	// L332
        float v224 = v223 ? (float)0.000000 : (float)v222;	// L333
        v71[0][v219][v220][v221] = v224;	// L334
      }
    }
  }
  for (int v225 = 0; v225 < 64; v225 += 1) {	// L338
    for (int v226 = 0; v226 < 34; v226 += 1) {	// L339
      for (int v227 = 0; v227 < 34; v227 += 1) {	// L340
        v70[0][v225][v226][v227] = 0.000000;	// L341
      }
    }
  }
  for (int v228 = 0; v228 < 64; v228 += 1) {	// L345
    for (int v229 = 0; v229 < 32; v229 += 1) {	// L346
      for (int v230 = 0; v230 < 32; v230 += 1) {	// L347
        float v231 = v71[0][v228][v229][v230];	// L348
        v70[0][v228][(v229 + 1)][(v230 + 1)] = v231;	// L349
      }
    }
  }
  for (int v232 = 0; v232 < 64; v232 += 1) {	// L353
    for (int v233 = 0; v233 < 3; v233 += 1) {	// L354
      for (int v234 = 0; v234 < 3; v234 += 1) {	// L355
        for (int v235 = 0; v235 < 128; v235 += 1) {	// L356
          for (int v236 = 0; v236 < 16; v236 += 1) {	// L357
            for (int v237 = 0; v237 < 16; v237 += 1) {	// L358
              float v238 = v70[0][v232][((v236 * 2) + v233)][((v237 * 2) + v234)];	// L359
              float v239 = v6[v235][v232][v233][v234];	// L360
              float v240 = v69[0][v235][v236][v237];	// L361
              float v241;
              if (v232 == 0 && v233 == 0 && v234 == 0) {	// L362
                v241 = 0.000000;	// L363
              } else {
                v241 = v240;	// L365
              }
              float v242 = v238 * v239;	// L367
              float v243 = v241 + v242;	// L368
              v69[0][v235][v236][v237] = v243;	// L369
            }
          }
        }
      }
    }
  }
  for (int v244 = 0; v244 < 128; v244 += 1) {	// L376
    for (int v245 = 0; v245 < 16; v245 += 1) {	// L377
      for (int v246 = 0; v246 < 16; v246 += 1) {	// L378
        float v247 = v69[0][v244][v245][v246];	// L379
        bool v248 = v247 < 0.000000;	// L380
        float v249 = v248 ? (float)0.000000 : (float)v247;	// L381
        v68[0][v244][v245][v246] = v249;	// L382
      }
    }
  }
  for (int v250 = 0; v250 < 128; v250 += 1) {	// L386
    for (int v251 = 0; v251 < 18; v251 += 1) {	// L387
      for (int v252 = 0; v252 < 18; v252 += 1) {	// L388
        v67[0][v250][v251][v252] = 0.000000;	// L389
      }
    }
  }
  for (int v253 = 0; v253 < 128; v253 += 1) {	// L393
    for (int v254 = 0; v254 < 16; v254 += 1) {	// L394
      for (int v255 = 0; v255 < 16; v255 += 1) {	// L395
        float v256 = v68[0][v253][v254][v255];	// L396
        v67[0][v253][(v254 + 1)][(v255 + 1)] = v256;	// L397
      }
    }
  }
  for (int v257 = 0; v257 < 128; v257 += 1) {	// L401
    for (int v258 = 0; v258 < 3; v258 += 1) {	// L402
      for (int v259 = 0; v259 < 3; v259 += 1) {	// L403
        for (int v260 = 0; v260 < 128; v260 += 1) {	// L404
          for (int v261 = 0; v261 < 16; v261 += 1) {	// L405
            for (int v262 = 0; v262 < 16; v262 += 1) {	// L406
              float v263 = v67[0][v257][(v261 + v258)][(v262 + v259)];	// L407
              float v264 = v7[v260][v257][v258][v259];	// L408
              float v265 = v66[0][v260][v261][v262];	// L409
              float v266;
              if (v257 == 0 && v258 == 0 && v259 == 0) {	// L410
                v266 = 0.000000;	// L411
              } else {
                v266 = v265;	// L413
              }
              float v267 = v263 * v264;	// L415
              float v268 = v266 + v267;	// L416
              v66[0][v260][v261][v262] = v268;	// L417
            }
          }
        }
      }
    }
  }
  for (int v269 = 0; v269 < 64; v269 += 1) {	// L424
    for (int v270 = 0; v270 < 128; v270 += 1) {	// L425
      for (int v271 = 0; v271 < 16; v271 += 1) {	// L426
        for (int v272 = 0; v272 < 16; v272 += 1) {	// L427
          float v273 = v71[0][v269][(v271 * 2)][(v272 * 2)];	// L428
          float v274 = v8[v270][v269][0][0];	// L429
          float v275 = v65[0][v270][v271][v272];	// L430
          float v276;
          if (v269 == 0) {	// L431
            v276 = 0.000000;	// L432
          } else {
            v276 = v275;	// L434
          }
          float v277 = v273 * v274;	// L436
          float v278 = v276 + v277;	// L437
          v65[0][v270][v271][v272] = v278;	// L438
        }
      }
    }
  }
  for (int v279 = 0; v279 < 128; v279 += 1) {	// L443
    for (int v280 = 0; v280 < 16; v280 += 1) {	// L444
      for (int v281 = 0; v281 < 16; v281 += 1) {	// L445
        float v282 = v66[0][v279][v280][v281];	// L446
        float v283 = v65[0][v279][v280][v281];	// L447
        float v284 = v282 + v283;	// L448
        v64[0][v279][v280][v281] = v284;	// L449
      }
    }
  }
  for (int v285 = 0; v285 < 128; v285 += 1) {	// L453
    for (int v286 = 0; v286 < 16; v286 += 1) {	// L454
      for (int v287 = 0; v287 < 16; v287 += 1) {	// L455
        float v288 = v64[0][v285][v286][v287];	// L456
        bool v289 = v288 < 0.000000;	// L457
        float v290 = v289 ? (float)0.000000 : (float)v288;	// L458
        v63[0][v285][v286][v287] = v290;	// L459
      }
    }
  }
  for (int v291 = 0; v291 < 128; v291 += 1) {	// L463
    for (int v292 = 0; v292 < 18; v292 += 1) {	// L464
      for (int v293 = 0; v293 < 18; v293 += 1) {	// L465
        v62[0][v291][v292][v293] = 0.000000;	// L466
      }
    }
  }
  for (int v294 = 0; v294 < 128; v294 += 1) {	// L470
    for (int v295 = 0; v295 < 16; v295 += 1) {	// L471
      for (int v296 = 0; v296 < 16; v296 += 1) {	// L472
        float v297 = v63[0][v294][v295][v296];	// L473
        v62[0][v294][(v295 + 1)][(v296 + 1)] = v297;	// L474
      }
    }
  }
  for (int v298 = 0; v298 < 128; v298 += 1) {	// L478
    for (int v299 = 0; v299 < 3; v299 += 1) {	// L479
      for (int v300 = 0; v300 < 3; v300 += 1) {	// L480
        for (int v301 = 0; v301 < 128; v301 += 1) {	// L481
          for (int v302 = 0; v302 < 16; v302 += 1) {	// L482
            for (int v303 = 0; v303 < 16; v303 += 1) {	// L483
              float v304 = v62[0][v298][(v302 + v299)][(v303 + v300)];	// L484
              float v305 = v9[v301][v298][v299][v300];	// L485
              float v306 = v61[0][v301][v302][v303];	// L486
              float v307;
              if (v298 == 0 && v299 == 0 && v300 == 0) {	// L487
                v307 = 0.000000;	// L488
              } else {
                v307 = v306;	// L490
              }
              float v308 = v304 * v305;	// L492
              float v309 = v307 + v308;	// L493
              v61[0][v301][v302][v303] = v309;	// L494
            }
          }
        }
      }
    }
  }
  for (int v310 = 0; v310 < 128; v310 += 1) {	// L501
    for (int v311 = 0; v311 < 16; v311 += 1) {	// L502
      for (int v312 = 0; v312 < 16; v312 += 1) {	// L503
        float v313 = v61[0][v310][v311][v312];	// L504
        bool v314 = v313 < 0.000000;	// L505
        float v315 = v314 ? (float)0.000000 : (float)v313;	// L506
        v60[0][v310][v311][v312] = v315;	// L507
      }
    }
  }
  for (int v316 = 0; v316 < 128; v316 += 1) {	// L511
    for (int v317 = 0; v317 < 18; v317 += 1) {	// L512
      for (int v318 = 0; v318 < 18; v318 += 1) {	// L513
        v59[0][v316][v317][v318] = 0.000000;	// L514
      }
    }
  }
  for (int v319 = 0; v319 < 128; v319 += 1) {	// L518
    for (int v320 = 0; v320 < 16; v320 += 1) {	// L519
      for (int v321 = 0; v321 < 16; v321 += 1) {	// L520
        float v322 = v60[0][v319][v320][v321];	// L521
        v59[0][v319][(v320 + 1)][(v321 + 1)] = v322;	// L522
      }
    }
  }
  for (int v323 = 0; v323 < 128; v323 += 1) {	// L526
    for (int v324 = 0; v324 < 3; v324 += 1) {	// L527
      for (int v325 = 0; v325 < 3; v325 += 1) {	// L528
        for (int v326 = 0; v326 < 128; v326 += 1) {	// L529
          for (int v327 = 0; v327 < 16; v327 += 1) {	// L530
            for (int v328 = 0; v328 < 16; v328 += 1) {	// L531
              float v329 = v59[0][v323][(v327 + v324)][(v328 + v325)];	// L532
              float v330 = v10[v326][v323][v324][v325];	// L533
              float v331 = v58[0][v326][v327][v328];	// L534
              float v332;
              if (v323 == 0 && v324 == 0 && v325 == 0) {	// L535
                v332 = 0.000000;	// L536
              } else {
                v332 = v331;	// L538
              }
              float v333 = v329 * v330;	// L540
              float v334 = v332 + v333;	// L541
              v58[0][v326][v327][v328] = v334;	// L542
            }
          }
        }
      }
    }
  }
  for (int v335 = 0; v335 < 128; v335 += 1) {	// L549
    for (int v336 = 0; v336 < 16; v336 += 1) {	// L550
      for (int v337 = 0; v337 < 16; v337 += 1) {	// L551
        float v338 = v58[0][v335][v336][v337];	// L552
        float v339 = v63[0][v335][v336][v337];	// L553
        float v340 = v338 + v339;	// L554
        v57[0][v335][v336][v337] = v340;	// L555
      }
    }
  }
  for (int v341 = 0; v341 < 128; v341 += 1) {	// L559
    for (int v342 = 0; v342 < 16; v342 += 1) {	// L560
      for (int v343 = 0; v343 < 16; v343 += 1) {	// L561
        float v344 = v57[0][v341][v342][v343];	// L562
        bool v345 = v344 < 0.000000;	// L563
        float v346 = v345 ? (float)0.000000 : (float)v344;	// L564
        v56[0][v341][v342][v343] = v346;	// L565
      }
    }
  }
  for (int v347 = 0; v347 < 128; v347 += 1) {	// L569
    for (int v348 = 0; v348 < 18; v348 += 1) {	// L570
      for (int v349 = 0; v349 < 18; v349 += 1) {	// L571
        v55[0][v347][v348][v349] = 0.000000;	// L572
      }
    }
  }
  for (int v350 = 0; v350 < 128; v350 += 1) {	// L576
    for (int v351 = 0; v351 < 16; v351 += 1) {	// L577
      for (int v352 = 0; v352 < 16; v352 += 1) {	// L578
        float v353 = v56[0][v350][v351][v352];	// L579
        v55[0][v350][(v351 + 1)][(v352 + 1)] = v353;	// L580
      }
    }
  }
  for (int v354 = 0; v354 < 128; v354 += 1) {	// L584
    for (int v355 = 0; v355 < 3; v355 += 1) {	// L585
      for (int v356 = 0; v356 < 3; v356 += 1) {	// L586
        for (int v357 = 0; v357 < 256; v357 += 1) {	// L587
          for (int v358 = 0; v358 < 8; v358 += 1) {	// L588
            for (int v359 = 0; v359 < 8; v359 += 1) {	// L589
              float v360 = v55[0][v354][((v358 * 2) + v355)][((v359 * 2) + v356)];	// L590
              float v361 = v11[v357][v354][v355][v356];	// L591
              float v362 = v54[0][v357][v358][v359];	// L592
              float v363;
              if (v354 == 0 && v355 == 0 && v356 == 0) {	// L593
                v363 = 0.000000;	// L594
              } else {
                v363 = v362;	// L596
              }
              float v364 = v360 * v361;	// L598
              float v365 = v363 + v364;	// L599
              v54[0][v357][v358][v359] = v365;	// L600
            }
          }
        }
      }
    }
  }
  for (int v366 = 0; v366 < 256; v366 += 1) {	// L607
    for (int v367 = 0; v367 < 8; v367 += 1) {	// L608
      for (int v368 = 0; v368 < 8; v368 += 1) {	// L609
        float v369 = v54[0][v366][v367][v368];	// L610
        bool v370 = v369 < 0.000000;	// L611
        float v371 = v370 ? (float)0.000000 : (float)v369;	// L612
        v53[0][v366][v367][v368] = v371;	// L613
      }
    }
  }
  for (int v372 = 0; v372 < 256; v372 += 1) {	// L617
    for (int v373 = 0; v373 < 10; v373 += 1) {	// L618
      for (int v374 = 0; v374 < 10; v374 += 1) {	// L619
        v52[0][v372][v373][v374] = 0.000000;	// L620
      }
    }
  }
  for (int v375 = 0; v375 < 256; v375 += 1) {	// L624
    for (int v376 = 0; v376 < 8; v376 += 1) {	// L625
      for (int v377 = 0; v377 < 8; v377 += 1) {	// L626
        float v378 = v53[0][v375][v376][v377];	// L627
        v52[0][v375][(v376 + 1)][(v377 + 1)] = v378;	// L628
      }
    }
  }
  for (int v379 = 0; v379 < 256; v379 += 1) {	// L632
    for (int v380 = 0; v380 < 3; v380 += 1) {	// L633
      for (int v381 = 0; v381 < 3; v381 += 1) {	// L634
        for (int v382 = 0; v382 < 256; v382 += 1) {	// L635
          for (int v383 = 0; v383 < 8; v383 += 1) {	// L636
            for (int v384 = 0; v384 < 8; v384 += 1) {	// L637
              float v385 = v52[0][v379][(v383 + v380)][(v384 + v381)];	// L638
              float v386 = v12[v382][v379][v380][v381];	// L639
              float v387 = v51[0][v382][v383][v384];	// L640
              float v388;
              if (v379 == 0 && v380 == 0 && v381 == 0) {	// L641
                v388 = 0.000000;	// L642
              } else {
                v388 = v387;	// L644
              }
              float v389 = v385 * v386;	// L646
              float v390 = v388 + v389;	// L647
              v51[0][v382][v383][v384] = v390;	// L648
            }
          }
        }
      }
    }
  }
  for (int v391 = 0; v391 < 128; v391 += 1) {	// L655
    for (int v392 = 0; v392 < 256; v392 += 1) {	// L656
      for (int v393 = 0; v393 < 8; v393 += 1) {	// L657
        for (int v394 = 0; v394 < 8; v394 += 1) {	// L658
          float v395 = v56[0][v391][(v393 * 2)][(v394 * 2)];	// L659
          float v396 = v13[v392][v391][0][0];	// L660
          float v397 = v50[0][v392][v393][v394];	// L661
          float v398;
          if (v391 == 0) {	// L662
            v398 = 0.000000;	// L663
          } else {
            v398 = v397;	// L665
          }
          float v399 = v395 * v396;	// L667
          float v400 = v398 + v399;	// L668
          v50[0][v392][v393][v394] = v400;	// L669
        }
      }
    }
  }
  for (int v401 = 0; v401 < 256; v401 += 1) {	// L674
    for (int v402 = 0; v402 < 8; v402 += 1) {	// L675
      for (int v403 = 0; v403 < 8; v403 += 1) {	// L676
        float v404 = v51[0][v401][v402][v403];	// L677
        float v405 = v50[0][v401][v402][v403];	// L678
        float v406 = v404 + v405;	// L679
        v49[0][v401][v402][v403] = v406;	// L680
      }
    }
  }
  for (int v407 = 0; v407 < 256; v407 += 1) {	// L684
    for (int v408 = 0; v408 < 8; v408 += 1) {	// L685
      for (int v409 = 0; v409 < 8; v409 += 1) {	// L686
        float v410 = v49[0][v407][v408][v409];	// L687
        bool v411 = v410 < 0.000000;	// L688
        float v412 = v411 ? (float)0.000000 : (float)v410;	// L689
        v48[0][v407][v408][v409] = v412;	// L690
      }
    }
  }
  for (int v413 = 0; v413 < 256; v413 += 1) {	// L694
    for (int v414 = 0; v414 < 10; v414 += 1) {	// L695
      for (int v415 = 0; v415 < 10; v415 += 1) {	// L696
        v47[0][v413][v414][v415] = 0.000000;	// L697
      }
    }
  }
  for (int v416 = 0; v416 < 256; v416 += 1) {	// L701
    for (int v417 = 0; v417 < 8; v417 += 1) {	// L702
      for (int v418 = 0; v418 < 8; v418 += 1) {	// L703
        float v419 = v48[0][v416][v417][v418];	// L704
        v47[0][v416][(v417 + 1)][(v418 + 1)] = v419;	// L705
      }
    }
  }
  for (int v420 = 0; v420 < 256; v420 += 1) {	// L709
    for (int v421 = 0; v421 < 3; v421 += 1) {	// L710
      for (int v422 = 0; v422 < 3; v422 += 1) {	// L711
        for (int v423 = 0; v423 < 256; v423 += 1) {	// L712
          for (int v424 = 0; v424 < 8; v424 += 1) {	// L713
            for (int v425 = 0; v425 < 8; v425 += 1) {	// L714
              float v426 = v47[0][v420][(v424 + v421)][(v425 + v422)];	// L715
              float v427 = v14[v423][v420][v421][v422];	// L716
              float v428 = v46[0][v423][v424][v425];	// L717
              float v429;
              if (v420 == 0 && v421 == 0 && v422 == 0) {	// L718
                v429 = 0.000000;	// L719
              } else {
                v429 = v428;	// L721
              }
              float v430 = v426 * v427;	// L723
              float v431 = v429 + v430;	// L724
              v46[0][v423][v424][v425] = v431;	// L725
            }
          }
        }
      }
    }
  }
  for (int v432 = 0; v432 < 256; v432 += 1) {	// L732
    for (int v433 = 0; v433 < 8; v433 += 1) {	// L733
      for (int v434 = 0; v434 < 8; v434 += 1) {	// L734
        float v435 = v46[0][v432][v433][v434];	// L735
        bool v436 = v435 < 0.000000;	// L736
        float v437 = v436 ? (float)0.000000 : (float)v435;	// L737
        v45[0][v432][v433][v434] = v437;	// L738
      }
    }
  }
  for (int v438 = 0; v438 < 256; v438 += 1) {	// L742
    for (int v439 = 0; v439 < 10; v439 += 1) {	// L743
      for (int v440 = 0; v440 < 10; v440 += 1) {	// L744
        v44[0][v438][v439][v440] = 0.000000;	// L745
      }
    }
  }
  for (int v441 = 0; v441 < 256; v441 += 1) {	// L749
    for (int v442 = 0; v442 < 8; v442 += 1) {	// L750
      for (int v443 = 0; v443 < 8; v443 += 1) {	// L751
        float v444 = v45[0][v441][v442][v443];	// L752
        v44[0][v441][(v442 + 1)][(v443 + 1)] = v444;	// L753
      }
    }
  }
  for (int v445 = 0; v445 < 256; v445 += 1) {	// L757
    for (int v446 = 0; v446 < 3; v446 += 1) {	// L758
      for (int v447 = 0; v447 < 3; v447 += 1) {	// L759
        for (int v448 = 0; v448 < 256; v448 += 1) {	// L760
          for (int v449 = 0; v449 < 8; v449 += 1) {	// L761
            for (int v450 = 0; v450 < 8; v450 += 1) {	// L762
              float v451 = v44[0][v445][(v449 + v446)][(v450 + v447)];	// L763
              float v452 = v15[v448][v445][v446][v447];	// L764
              float v453 = v43[0][v448][v449][v450];	// L765
              float v454;
              if (v445 == 0 && v446 == 0 && v447 == 0) {	// L766
                v454 = 0.000000;	// L767
              } else {
                v454 = v453;	// L769
              }
              float v455 = v451 * v452;	// L771
              float v456 = v454 + v455;	// L772
              v43[0][v448][v449][v450] = v456;	// L773
            }
          }
        }
      }
    }
  }
  for (int v457 = 0; v457 < 256; v457 += 1) {	// L780
    for (int v458 = 0; v458 < 8; v458 += 1) {	// L781
      for (int v459 = 0; v459 < 8; v459 += 1) {	// L782
        float v460 = v43[0][v457][v458][v459];	// L783
        float v461 = v48[0][v457][v458][v459];	// L784
        float v462 = v460 + v461;	// L785
        v42[0][v457][v458][v459] = v462;	// L786
      }
    }
  }
  for (int v463 = 0; v463 < 256; v463 += 1) {	// L790
    for (int v464 = 0; v464 < 8; v464 += 1) {	// L791
      for (int v465 = 0; v465 < 8; v465 += 1) {	// L792
        float v466 = v42[0][v463][v464][v465];	// L793
        bool v467 = v466 < 0.000000;	// L794
        float v468 = v467 ? (float)0.000000 : (float)v466;	// L795
        v41[0][v463][v464][v465] = v468;	// L796
      }
    }
  }
  for (int v469 = 0; v469 < 256; v469 += 1) {	// L800
    for (int v470 = 0; v470 < 10; v470 += 1) {	// L801
      for (int v471 = 0; v471 < 10; v471 += 1) {	// L802
        v40[0][v469][v470][v471] = 0.000000;	// L803
      }
    }
  }
  for (int v472 = 0; v472 < 256; v472 += 1) {	// L807
    for (int v473 = 0; v473 < 8; v473 += 1) {	// L808
      for (int v474 = 0; v474 < 8; v474 += 1) {	// L809
        float v475 = v41[0][v472][v473][v474];	// L810
        v40[0][v472][(v473 + 1)][(v474 + 1)] = v475;	// L811
      }
    }
  }
  for (int v476 = 0; v476 < 256; v476 += 1) {	// L815
    for (int v477 = 0; v477 < 3; v477 += 1) {	// L816
      for (int v478 = 0; v478 < 3; v478 += 1) {	// L817
        for (int v479 = 0; v479 < 512; v479 += 1) {	// L818
          for (int v480 = 0; v480 < 4; v480 += 1) {	// L819
            for (int v481 = 0; v481 < 4; v481 += 1) {	// L820
              float v482 = v40[0][v476][((v480 * 2) + v477)][((v481 * 2) + v478)];	// L821
              float v483 = v16[v479][v476][v477][v478];	// L822
              float v484 = v39[0][v479][v480][v481];	// L823
              float v485;
              if (v476 == 0 && v477 == 0 && v478 == 0) {	// L824
                v485 = 0.000000;	// L825
              } else {
                v485 = v484;	// L827
              }
              float v486 = v482 * v483;	// L829
              float v487 = v485 + v486;	// L830
              v39[0][v479][v480][v481] = v487;	// L831
            }
          }
        }
      }
    }
  }
  for (int v488 = 0; v488 < 512; v488 += 1) {	// L838
    for (int v489 = 0; v489 < 4; v489 += 1) {	// L839
      for (int v490 = 0; v490 < 4; v490 += 1) {	// L840
        float v491 = v39[0][v488][v489][v490];	// L841
        bool v492 = v491 < 0.000000;	// L842
        float v493 = v492 ? (float)0.000000 : (float)v491;	// L843
        v38[0][v488][v489][v490] = v493;	// L844
      }
    }
  }
  for (int v494 = 0; v494 < 512; v494 += 1) {	// L848
    for (int v495 = 0; v495 < 6; v495 += 1) {	// L849
      for (int v496 = 0; v496 < 6; v496 += 1) {	// L850
        v37[0][v494][v495][v496] = 0.000000;	// L851
      }
    }
  }
  for (int v497 = 0; v497 < 512; v497 += 1) {	// L855
    for (int v498 = 0; v498 < 4; v498 += 1) {	// L856
      for (int v499 = 0; v499 < 4; v499 += 1) {	// L857
        float v500 = v38[0][v497][v498][v499];	// L858
        v37[0][v497][(v498 + 1)][(v499 + 1)] = v500;	// L859
      }
    }
  }
  for (int v501 = 0; v501 < 512; v501 += 1) {	// L863
    for (int v502 = 0; v502 < 3; v502 += 1) {	// L864
      for (int v503 = 0; v503 < 3; v503 += 1) {	// L865
        for (int v504 = 0; v504 < 512; v504 += 1) {	// L866
          for (int v505 = 0; v505 < 4; v505 += 1) {	// L867
            for (int v506 = 0; v506 < 4; v506 += 1) {	// L868
              float v507 = v37[0][v501][(v505 + v502)][(v506 + v503)];	// L869
              float v508 = v17[v504][v501][v502][v503];	// L870
              float v509 = v36[0][v504][v505][v506];	// L871
              float v510;
              if (v501 == 0 && v502 == 0 && v503 == 0) {	// L872
                v510 = 0.000000;	// L873
              } else {
                v510 = v509;	// L875
              }
              float v511 = v507 * v508;	// L877
              float v512 = v510 + v511;	// L878
              v36[0][v504][v505][v506] = v512;	// L879
            }
          }
        }
      }
    }
  }
  for (int v513 = 0; v513 < 256; v513 += 1) {	// L886
    for (int v514 = 0; v514 < 512; v514 += 1) {	// L887
      for (int v515 = 0; v515 < 4; v515 += 1) {	// L888
        for (int v516 = 0; v516 < 4; v516 += 1) {	// L889
          float v517 = v41[0][v513][(v515 * 2)][(v516 * 2)];	// L890
          float v518 = v18[v514][v513][0][0];	// L891
          float v519 = v35[0][v514][v515][v516];	// L892
          float v520;
          if (v513 == 0) {	// L893
            v520 = 0.000000;	// L894
          } else {
            v520 = v519;	// L896
          }
          float v521 = v517 * v518;	// L898
          float v522 = v520 + v521;	// L899
          v35[0][v514][v515][v516] = v522;	// L900
        }
      }
    }
  }
  for (int v523 = 0; v523 < 512; v523 += 1) {	// L905
    for (int v524 = 0; v524 < 4; v524 += 1) {	// L906
      for (int v525 = 0; v525 < 4; v525 += 1) {	// L907
        float v526 = v36[0][v523][v524][v525];	// L908
        float v527 = v35[0][v523][v524][v525];	// L909
        float v528 = v526 + v527;	// L910
        v34[0][v523][v524][v525] = v528;	// L911
      }
    }
  }
  for (int v529 = 0; v529 < 512; v529 += 1) {	// L915
    for (int v530 = 0; v530 < 4; v530 += 1) {	// L916
      for (int v531 = 0; v531 < 4; v531 += 1) {	// L917
        float v532 = v34[0][v529][v530][v531];	// L918
        bool v533 = v532 < 0.000000;	// L919
        float v534 = v533 ? (float)0.000000 : (float)v532;	// L920
        v33[0][v529][v530][v531] = v534;	// L921
      }
    }
  }
  for (int v535 = 0; v535 < 512; v535 += 1) {	// L925
    for (int v536 = 0; v536 < 6; v536 += 1) {	// L926
      for (int v537 = 0; v537 < 6; v537 += 1) {	// L927
        v32[0][v535][v536][v537] = 0.000000;	// L928
      }
    }
  }
  for (int v538 = 0; v538 < 512; v538 += 1) {	// L932
    for (int v539 = 0; v539 < 4; v539 += 1) {	// L933
      for (int v540 = 0; v540 < 4; v540 += 1) {	// L934
        float v541 = v33[0][v538][v539][v540];	// L935
        v32[0][v538][(v539 + 1)][(v540 + 1)] = v541;	// L936
      }
    }
  }
  for (int v542 = 0; v542 < 512; v542 += 1) {	// L940
    for (int v543 = 0; v543 < 3; v543 += 1) {	// L941
      for (int v544 = 0; v544 < 3; v544 += 1) {	// L942
        for (int v545 = 0; v545 < 512; v545 += 1) {	// L943
          for (int v546 = 0; v546 < 4; v546 += 1) {	// L944
            for (int v547 = 0; v547 < 4; v547 += 1) {	// L945
              float v548 = v32[0][v542][(v546 + v543)][(v547 + v544)];	// L946
              float v549 = v19[v545][v542][v543][v544];	// L947
              float v550 = v31[0][v545][v546][v547];	// L948
              float v551;
              if (v542 == 0 && v543 == 0 && v544 == 0) {	// L949
                v551 = 0.000000;	// L950
              } else {
                v551 = v550;	// L952
              }
              float v552 = v548 * v549;	// L954
              float v553 = v551 + v552;	// L955
              v31[0][v545][v546][v547] = v553;	// L956
            }
          }
        }
      }
    }
  }
  for (int v554 = 0; v554 < 512; v554 += 1) {	// L963
    for (int v555 = 0; v555 < 4; v555 += 1) {	// L964
      for (int v556 = 0; v556 < 4; v556 += 1) {	// L965
        float v557 = v31[0][v554][v555][v556];	// L966
        bool v558 = v557 < 0.000000;	// L967
        float v559 = v558 ? (float)0.000000 : (float)v557;	// L968
        v30[0][v554][v555][v556] = v559;	// L969
      }
    }
  }
  for (int v560 = 0; v560 < 512; v560 += 1) {	// L973
    for (int v561 = 0; v561 < 6; v561 += 1) {	// L974
      for (int v562 = 0; v562 < 6; v562 += 1) {	// L975
        v29[0][v560][v561][v562] = 0.000000;	// L976
      }
    }
  }
  for (int v563 = 0; v563 < 512; v563 += 1) {	// L980
    for (int v564 = 0; v564 < 4; v564 += 1) {	// L981
      for (int v565 = 0; v565 < 4; v565 += 1) {	// L982
        float v566 = v30[0][v563][v564][v565];	// L983
        v29[0][v563][(v564 + 1)][(v565 + 1)] = v566;	// L984
      }
    }
  }
  for (int v567 = 0; v567 < 512; v567 += 1) {	// L988
    for (int v568 = 0; v568 < 3; v568 += 1) {	// L989
      for (int v569 = 0; v569 < 3; v569 += 1) {	// L990
        for (int v570 = 0; v570 < 512; v570 += 1) {	// L991
          for (int v571 = 0; v571 < 4; v571 += 1) {	// L992
            for (int v572 = 0; v572 < 4; v572 += 1) {	// L993
              float v573 = v29[0][v567][(v571 + v568)][(v572 + v569)];	// L994
              float v574 = v20[v570][v567][v568][v569];	// L995
              float v575 = v28[0][v570][v571][v572];	// L996
              float v576;
              if (v567 == 0 && v568 == 0 && v569 == 0) {	// L997
                v576 = 0.000000;	// L998
              } else {
                v576 = v575;	// L1000
              }
              float v577 = v573 * v574;	// L1002
              float v578 = v576 + v577;	// L1003
              v28[0][v570][v571][v572] = v578;	// L1004
            }
          }
        }
      }
    }
  }
  for (int v579 = 0; v579 < 512; v579 += 1) {	// L1011
    for (int v580 = 0; v580 < 4; v580 += 1) {	// L1012
      for (int v581 = 0; v581 < 4; v581 += 1) {	// L1013
        float v582 = v28[0][v579][v580][v581];	// L1014
        float v583 = v33[0][v579][v580][v581];	// L1015
        float v584 = v582 + v583;	// L1016
        v27[0][v579][v580][v581] = v584;	// L1017
      }
    }
  }
  for (int v585 = 0; v585 < 512; v585 += 1) {	// L1021
    for (int v586 = 0; v586 < 4; v586 += 1) {	// L1022
      for (int v587 = 0; v587 < 4; v587 += 1) {	// L1023
        float v588 = v27[0][v585][v586][v587];	// L1024
        bool v589 = v588 < 0.000000;	// L1025
        float v590 = v589 ? (float)0.000000 : (float)v588;	// L1026
        v26[0][v585][v586][v587] = v590;	// L1027
      }
    }
  }
  for (int v591 = 0; v591 < 512; v591 += 1) {	// L1031
    v25[0][v591][0][0] = 0.000000;	// L1032
  }
  for (int v592 = 0; v592 < 4; v592 += 1) {	// L1034
    for (int v593 = 0; v593 < 4; v593 += 1) {	// L1035
      for (int v594 = 0; v594 < 512; v594 += 1) {	// L1036
        float v595 = v26[0][v594][v592][v593];	// L1037
        float v596 = v25[0][v594][0][0];	// L1038
        float v597 = v596 + v595;	// L1039
        v25[0][v594][0][0] = v597;	// L1040
      }
    }
  }
  float v598 = 16;	// L1044
  for (int v599 = 0; v599 < 512; v599 += 1) {	// L1045
    float v600 = v25[0][v599][0][0];	// L1046
    float v601 = v600 / v598;	// L1047
    v25[0][v599][0][0] = v601;	// L1048
  }
  for (int v602 = 0; v602 < 512; v602 += 1) {	// L1050
    float v603 = v25[0][v602][0][0];	// L1051
    v24[0][v602] = v603;	// L1052
  }
  #pragma HLS resource variable=v23 core=ram_s2p_bram

  for (int v605 = 0; v605 < 512; v605 += 1) {	// L1055
    for (int v606 = 0; v606 < 10; v606 += 1) {	// L1056
      float v607 = v24[0][v605];	// L1057
      float v608 = v21[v606][v605];	// L1058
      float v609 = v22[0][v606];	// L1059
      float v610;
      if (v605 == 0) {	// L1060
        v610 = 0.000000;	// L1061
      } else {
        v610 = v609;	// L1063
      }
      float v611 = v607 * v608;	// L1065
      float v612 = v610 + v611;	// L1066
      v22[0][v606] = v612;	// L1067
      float v613 = 1.000000 * v612;	// L1068
      float v614 = v23[v606];	// L1069
      float v615 = 1.000000 * v614;	// L1070
      float v616 = v613 + v615;	// L1071
      if (((-v605) + 511) == 0) {	// L1072
        v22[0][v606] = v616;	// L1073
      }
    }
  }
}

