#include "types.h"

/* Initialized rodata at 0x8007E140..0x8007E178 (ROM 0x7ED40..0x7ED78); consumer: func_8000DD40. */
typedef struct Rodata8007E140 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    f32 value20;
    u32 word24;
    u32 word28;
    u32 word2C;
    u32 word30;
    u32 word34;
} Rodata8007E140;

const Rodata8007E140 D_8007E140 = {
    0x8000DD8C,
    0x8000DEC8,
    0x8000DF14,
    0x8000DF70,
    0x8000E100,
    0x8000E134,
    0x8000E240,
    0x8000E26C,
    360.5f,
    0x8000E29C,
    0x8000E2B4,
    0x8000E2C4,
    0x8000E2D4,
    0x8000E2E4,
};
