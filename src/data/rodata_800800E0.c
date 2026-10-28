#include "types.h"

/* Initialized rodata at 0x800800E0..0x800800E8 (ROM 0x80CE0..0x80CE8); consumer: func_800293FC. */
typedef struct Rodata800800E0 {
    char text0[5];
    u8 pad5[3];
} Rodata800800E0;

const Rodata800800E0 D_800800E0 = {
    "?\346ff\000",
    { 0x00, 0x00, 0x00 },
};
