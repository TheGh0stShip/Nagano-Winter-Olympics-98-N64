#include "types.h"

/* Initialized rodata at 0x80080720..0x8008075C (ROM 0x81320..0x8135C); consumer: func_8003C780. */
typedef struct Rodata80080720 {
    f32 value0;
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
    f64 value30;
    f32 value38;
} Rodata80080720;

const Rodata80080720 D_80080720 = {
    3.76900005f,
    0x8003C850,
    0x8003C890,
    0x8003C8F8,
    0x8003C908,
    0x8003C93C,
    0x8003C94C,
    0x8003C9E0,
    0x8003C964,
    0x8003C9E0,
    0x8003C9D0,
    0x00000000,
    0.047123891676382035,
    1.57079637f,
};
