#include "types.h"

/* Initialized rodata at 0x8007E028..0x8007E040 (ROM 0x7EC28..0x7EC40); consumer: func_8000AAC0. */
typedef struct Rodata8007E028 {
    f32 value0;
    f32 value4;
    f32 value8;
    f32 valueC;
    f32 value10;
    u32 word14;
} Rodata8007E028;

const Rodata8007E028 D_8007E028 = {
    75.8518524f,
    199.5f,
    0.0299999975f,
    0.0500000007f,
    1.20000005f,
    0x00000000,
};
