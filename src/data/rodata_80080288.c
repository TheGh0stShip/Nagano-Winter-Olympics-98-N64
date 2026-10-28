#include "types.h"

/* Initialized rodata at 0x80080288..0x800802B0 (ROM 0x80E88..0x80EB0); consumer: func_80030F88. */
typedef struct Rodata80080288 {
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
} Rodata80080288;

const Rodata80080288 D_80080288 = {
    0x800311B8,
    0x80031410,
    0x800311C0,
    0x800318A8,
    0x80031660,
    0x80031B34,
    0x80031CB0,
    0x80031AF0,
    0x80031C6C,
    0x800311B8,
};
