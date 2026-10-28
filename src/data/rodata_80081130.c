#include "types.h"

/* Initialized rodata at 0x80081130..0x80081154 (ROM 0x81D30..0x81D54); consumer: func_80058E20. */
typedef struct Rodata80081130 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
} Rodata80081130;

const Rodata80081130 D_80081130 = {
    0x8005921C,
    0x80059114,
    0x80059150,
    0x8005923C,
    0x8005923C,
    0x8005918C,
    0x800591D4,
    0x00000000,
    0x686C4C00,
};
