#include "types.h"

/* Initialized rodata at 0x80080320..0x80080338 (ROM 0x80F20..0x80F38); consumer: func_800359C0. */
typedef struct Rodata80080320 {
    f64 value0;
    f64 value8;
    f32 value10;
    u32 word14;
} Rodata80080320;

const Rodata80080320 D_80080320 = {
    3.141592653589793,
    180.0,
    0.0500000007f,
    0x00000000,
};
