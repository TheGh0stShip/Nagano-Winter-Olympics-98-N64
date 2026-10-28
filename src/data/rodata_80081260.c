#include "types.h"

/* Initialized rodata at 0x80081260..0x800812B0 (ROM 0x81E60..0x81EB0); consumer: func_8005C4E0. */
typedef struct Rodata80081260 {
    u32 word0;
    u32 word4;
    f64 value8;
    f64 value10;
    f64 value18;
    f64 value20;
    u32 word28;
    u32 word2C;
    f64 value30;
    f64 value38;
    u32 word40;
    u32 word44;
    u32 word48;
    u32 word4C;
} Rodata80081260;

const Rodata80081260 D_80081260 = {
    0x3FF00000,
    0x00000000,
    -0.16666659550427756,
    0.008333066246082155,
    -0.0001980960290193795,
    2.605780637968037e-06,
    0x3FD45F30,
    0x6DC9C883,
    3.1415926218032837,
    3.178650954705639e-08,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
};
