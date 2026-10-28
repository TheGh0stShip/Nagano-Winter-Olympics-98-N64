#include "types.h"

/* Initialized data at 0x80074680..0x800746B0 (ROM 0x75280..0x752B0); consumer: func_80049A78. */
typedef struct Data80074680 {
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
} Data80074680;

Data80074680 D_80074680 = {
    0x0C000E00,
    0x0E000900,
    0x09000B00,
    0x08000E00,
    0x0E000E00,
    0x0E000E00,
    0x0C001000,
    0x0E000E00,
    0x10000C00,
    0x0E000C00,
    0x0C000C00,
    0x10000000,
};
