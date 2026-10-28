#include "types.h"

/* Initialized rodata at 0x800810F0..0x80081118 (ROM 0x81CF0..0x81D18); consumer: func_80057D50. */
typedef struct Rodata800810F0 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
    u32 word24;
} Rodata800810F0;

const Rodata800810F0 D_800810F0 = {
    0x80057D80,
    0x80057E10,
    0x80057E10,
    0x80057D88,
    0x80057E10,
    0x80057E10,
    0x80057DF4,
    0x80057E04,
    0x80057DC4,
    0x00000000,
};
