#include "types.h"

/* Initialized rodata at 0x8007FC80..0x8007FCA0 (ROM 0x80880..0x808A0); consumer: func_80025008. */
typedef struct Rodata8007FC80 {
    f64 value0;
    f64 value8;
    f64 value10;
    u32 word18;
    u32 word1C;
} Rodata8007FC80;

const Rodata8007FC80 D_8007FC80 = {
    0.6,
    -0.01,
    0.01,
    0x00000000,
    0x00000000,
};
