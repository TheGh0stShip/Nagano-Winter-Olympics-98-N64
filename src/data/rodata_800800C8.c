#include "types.h"

/* Initialized rodata at 0x800800C8..0x800800D8 (ROM 0x80CC8..0x80CD8); consumer: func_80028DE0. */
typedef struct Rodata800800C8 {
    f64 value0;
    u32 word8;
    u32 wordC;
} Rodata800800C8;

const Rodata800800C8 D_800800C8 = {
    0.01,
    0x3F847AE1,
    0x47AE147B,
};
