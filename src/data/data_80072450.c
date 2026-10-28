#include "types.h"

/* Initialized data at 0x80072450..0x8007249C (ROM 0x73050..0x7309C); consumer: shared. */
typedef struct Data80072450 {
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
    u32 word38;
    u32 word3C;
    u32 word40;
    u32 word44;
    u32 word48;
} Data80072450;

Data80072450 D_80072450 = {
    0x00000000,
    0xC2BE0000,
    0x00000000,
    0x03E80000,
    0x0000000A,
    0x800636E0,
    0x060665D0,
    0x00000000,
    0x00000000,
    0x060057D8,
    0x00000000,
    0xC2BE0000,
    0x00000000,
    0x03E80000,
    0x00000010,
    0x80063718,
    0x060057D8,
    0x00000000,
    0x00000000,
};
