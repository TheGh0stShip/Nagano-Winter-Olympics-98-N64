#include "types.h"

/* Initialized rodata at 0x8007E6A0..0x8007E6E0 (ROM 0x7F2A0..0x7F2E0); consumer: func_8001A590. */
typedef struct Rodata8007E6A0 {
    char text0[14];
    u8 padE[2];
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
    u32 word38;
    u32 word3C;
} Rodata8007E6A0;

const Rodata8007E6A0 D_8007E6A0 = {
    "[ player %d ]\000",
    { 0x00, 0x00 },
    0x0A000000,
    0x25366400,
    0x0A000000,
    0x25367800,
    0x0A000000,
    0x25367800,
    0x0A000000,
    0x25366400,
    0x0A000000,
    0x25366400,
    0x0A000000,
    0x00000000,
};
