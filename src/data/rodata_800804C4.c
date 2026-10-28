#include "types.h"

/* Initialized rodata at 0x800804C4..0x80080514 (ROM 0x810C4..0x81114); consumer: func_8003DFA8. */
typedef struct Rodata800804C4 {
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
    u32 word4C;
} Rodata800804C4;

const Rodata800804C4 D_800804C4 = {
    0x00000000,
    0x43503A4E,
    0x6174696F,
    0x6E204F76,
    0x65720A00,
    0x43503A74,
    0x7279706C,
    0x61796572,
    0x204F7665,
    0x723D2564,
    0x0A000000,
    0x43504469,
    0x73706C61,
    0x79526570,
    0x6C61790A,
    0x00000000,
    0x43503A57,
    0x69706552,
    0x65706C61,
    0x790A0000,
};
