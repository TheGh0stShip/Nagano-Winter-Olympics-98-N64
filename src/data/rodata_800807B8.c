#include "types.h"

/* Initialized rodata at 0x800807B8..0x800807F8 (ROM 0x813B8..0x813F8); consumer: func_8003DCBC. */
typedef struct Rodata800807B8 {
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
    f64 value28;
    f32 value30;
    u32 word34;
    f64 value38;
} Rodata800807B8;

const Rodata800807B8 D_800807B8 = {
    0x8003DD04,
    0x8003DD90,
    0x8003DF6C,
    0x8003DF6C,
    0x8003DF6C,
    0x8003DEE8,
    0x8003DF6C,
    0x8003DF6C,
    0x8003DEF4,
    0x00000000,
    0.047123891676382035,
    26.666666f,
    0x00000000,
    0.047123891676382035,
};
