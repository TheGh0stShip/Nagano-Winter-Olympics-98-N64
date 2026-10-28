#include "types.h"

/* Initialized rodata at 0x80080264..0x80080288 (ROM 0x80E64..0x80E88); consumer: func_80030AA0. */
typedef struct Rodata80080264 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
} Rodata80080264;

const Rodata80080264 D_80080264 = {
    0x80030AF8,
    0x80030AEC,
    0x80030AF8,
    0x80030AEC,
    0x80030B04,
    0x80030B10,
    0x80030B04,
    0x80030B10,
    0x80030B1C,
};
