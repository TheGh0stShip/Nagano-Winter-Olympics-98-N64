#include "types.h"

/* Initialized rodata at 0x80080200..0x80080228 (ROM 0x80E00..0x80E28); consumer: func_8002F014. */
typedef struct Rodata80080200 {
    f64 value0;
    f64 value8;
    f64 value10;
    f64 value18;
    f32 value20;
    u32 word24;
} Rodata80080200;

const Rodata80080200 D_80080200 = {
    3.141592653589793,
    180.0,
    3.141592653589793,
    180.0,
    0.995000005f,
    0x00000000,
};
