#include "types.h"

/* Initialized rodata at 0x80080F98..0x80080FC0 (ROM 0x81B98..0x81BC0); consumer: func_8004EA50. */
typedef struct Rodata80080F98 {
    f64 value0;
    f64 value8;
    f64 value10;
    u32 word18;
    u32 word1C;
    u32 word20;
    u32 word24;
} Rodata80080F98;

const Rodata80080F98 D_80080F98 = {
    0.3183098861837907,
    3.1415926218032837,
    3.178650954705639e-08,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
};
