#include "types.h"

/* Initialized rodata at 0x8007E6E0..0x8007E7A0 (ROM 0x7F2E0..0x7F3A0); consumer: func_8001AB58. */
typedef struct Rodata8007E6E0 {
    char text0[11];
    u8 padB[1];
    u32 wordC;
    char text10[14];
    u8 pad1E[2];
    char text20[12];
    char text2C[11];
    u8 pad37[1];
    char text38[12];
    char text44[11];
    u8 pad4F[1];
    u32 word50;
    char text54[21];
    u8 pad69[3];
    char text6C[9];
    u8 pad75[3];
    char text78[13];
    u8 pad85[3];
    char text88[19];
    u8 pad9B[1];
    char text9C[19];
    u8 padAF[1];
    u32 wordB0;
    u32 wordB4;
    u32 wordB8;
    u32 wordBC;
} Rodata8007E6E0;

const Rodata8007E6E0 D_8007E6E0 = {
    "[WAZA %d] \000",
    { 0x00 },
    0x0A000000,
    "[pointer %2d]\000",
    { 0x00, 0x00 },
    ":[data %5x]\000",
    ":[buf %5x]\000",
    { 0x00 },
    ":[data %5x]\000",
    ":[buf %5x]\000",
    { 0x00 },
    0x0A000000,
    "***** WAZA %d ***** \000",
    { 0x00, 0x00, 0x00 },
    "[NO. %d]\000",
    { 0x00, 0x00, 0x00 },
    "[TOKUTEN %d]\000",
    { 0x00, 0x00, 0x00 },
    "[SPEED -%4d point]\000",
    { 0x00 },
    "[TECK  -%4d point]\000",
    { 0x00 },
    0x0A000000,
    0x00000000,
    0x00000000,
    0x00000000,
};
