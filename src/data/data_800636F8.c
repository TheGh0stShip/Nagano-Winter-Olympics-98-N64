#include "types.h"

/* Initialized data at 0x800636F8..0x80063718 (ROM 0x642F8..0x64318); consumer: func_80010874. */
typedef struct Data800636F8 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
} Data800636F8;

Data800636F8 D_800636F8 = {
    0x4000000C,
    0x00000001,
    0x40000013,
    0x00000000,
    0x40000013,
    0x00000001,
    0x40000011,
    0x00000000,
};
