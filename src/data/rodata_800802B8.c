#include "types.h"

/* Initialized rodata at 0x800802B8..0x800802D4 (ROM 0x80EB8..0x80ED4); consumer: func_80032074. */
typedef struct Rodata800802B8 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
} Rodata800802B8;

const Rodata800802B8 D_800802B8 = {
    0x800320C4,
    0x800320F8,
    0x80032114,
    0x8003218C,
    0x800321B4,
    0x80032230,
    0x800321D8,
};
