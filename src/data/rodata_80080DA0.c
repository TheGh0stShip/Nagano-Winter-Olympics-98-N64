#include "types.h"

/* Initialized rodata at 0x80080DA0..0x80080DB4 (ROM 0x819A0..0x819B4); consumer: func_80048EE4. */
typedef struct Rodata80080DA0 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
} Rodata80080DA0;

const Rodata80080DA0 D_80080DA0 = {
    0x80048F6C,
    0x80048FBC,
    0x80048FCC,
    0x80048FDC,
    0x80048FEC,
};
