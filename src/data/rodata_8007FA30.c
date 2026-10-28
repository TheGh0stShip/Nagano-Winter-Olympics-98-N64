#include "types.h"

/* Initialized rodata at 0x8007FA30..0x8007FA68 (ROM 0x80630..0x80668); consumer: func_80021840. */
typedef struct Rodata8007FA30 {
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
    u32 word28;
    u32 word2C;
    u32 word30;
    u32 word34;
} Rodata8007FA30;

const Rodata8007FA30 D_8007FA30 = {
    0x80021870,
    0x80021880,
    0x800218A0,
    0x800218B0,
    0x800218C0,
    0x800218D0,
    0x800218F0,
    0x800218E0,
    0x800218C0,
    0x80021890,
    0x80021890,
    0x80021900,
    0x80021900,
    0x00000000,
};
