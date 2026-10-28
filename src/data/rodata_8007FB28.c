#include "types.h"

/* Initialized rodata at 0x8007FB28..0x8007FB60 (ROM 0x80728..0x80760); consumer: func_80022A40. */
typedef struct Rodata8007FB28 {
    f64 value0;
    f64 value8;
    f64 value10;
    f64 value18;
    f64 value20;
    f64 value28;
    u32 word30;
    u32 word34;
} Rodata8007FB28;

const Rodata8007FB28 D_8007FB28 = {
    180.0,
    0.6,
    90.0,
    3.141592653589793,
    180.0,
    3.141592653589793,
    0x3FA99999,
    0x9999999A,
};
