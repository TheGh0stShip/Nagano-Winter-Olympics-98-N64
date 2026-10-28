#include "types.h"

/* Initialized rodata at 0x80080F70..0x80080F98 (ROM 0x81B70..0x81B98); consumer: shared. */
typedef struct Rodata80080F70 {
    u32 word0;
    u32 word4;
    f64 value8;
    f64 value10;
    f64 value18;
    f64 value20;
} Rodata80080F70;

const Rodata80080F70 D_80080F70 = {
    0x3FF00000,
    0x00000000,
    -0.16666659550427756,
    0.008333066246082155,
    -0.0001980960290193795,
    2.605780637968037e-06,
};
