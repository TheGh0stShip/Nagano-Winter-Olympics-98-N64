#include "types.h"

/* Initialized rodata at 0x80080D40..0x80080D50 (ROM 0x81940..0x81950); consumer: func_8004678C. */
typedef struct Rodata80080D40 {
    f32 value0;
    u32 word4;
    u32 word8;
    u32 wordC;
} Rodata80080D40;

const Rodata80080D40 D_80080D40 = {
    50000.0f,
    0x00000000,
    0x00000000,
    0x00000000,
};
