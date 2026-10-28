#include "types.h"

/* Initialized rodata at 0x800802B0..0x800802B8 (ROM 0x80EB0..0x80EB8); consumer: func_80035004. */
typedef struct Rodata800802B0 {
    u32 word0;
    u32 word4;
} Rodata800802B0;

const Rodata800802B0 D_800802B0 = {
    0x00000008,
    0x000C000E,
};
