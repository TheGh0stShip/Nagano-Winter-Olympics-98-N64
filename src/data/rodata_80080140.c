#include "types.h"

/* Initialized rodata at 0x80080140..0x80080158 (ROM 0x80D40..0x80D58); consumer: func_8002CE90. */
typedef struct Rodata80080140 {
    f32 value0;
    u32 word4;
    f64 value8;
    f64 value10;
} Rodata80080140;

const Rodata80080140 D_80080140 = {
    0.100000001f,
    0x00000000,
    0.01,
    0.01,
};
