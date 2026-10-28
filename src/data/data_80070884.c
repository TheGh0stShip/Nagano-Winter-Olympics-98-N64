#include "types.h"

/* Initialized data at 0x80070884..0x800708B0 (ROM 0x71484..0x714B0); consumer: func_80021FFC. */
typedef struct Data80070884 {
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
} Data80070884;

Data80070884 D_80070884 = {
    0x43020000,
    0x41F00000,
    0xC1700000,
    0x43480000,
    0x41F00000,
    0xC1A00000,
    0x43160000,
    0x42080000,
    0xC1A00000,
    0x00000000,
    0x00000000,
};
