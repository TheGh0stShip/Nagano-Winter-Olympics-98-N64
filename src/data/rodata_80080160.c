#include "types.h"

/* Initialized rodata at 0x80080160..0x80080168 (ROM 0x80D60..0x80D68); consumer: func_8002D700. */
typedef struct Rodata80080160 {
    f32 value0;
    u32 word4;
} Rodata80080160;

const Rodata80080160 D_80080160 = {
    0.00150000001f,
    0x00000000,
};
