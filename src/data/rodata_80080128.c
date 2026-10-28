#include "types.h"

/* Initialized rodata at 0x80080128..0x80080138 (ROM 0x80D28..0x80D38); consumer: func_8002BF54. */
typedef struct Rodata80080128 {
    f64 value0;
    u32 word8;
    u32 wordC;
} Rodata80080128;

const Rodata80080128 D_80080128 = {
    0.01,
    0x3FEB3333,
    0x33333333,
};
