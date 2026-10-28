#include "types.h"

/* Initialized rodata at 0x800800FC..0x80080108 (ROM 0x80CFC..0x80D08); consumer: func_80029870. */
typedef struct Rodata800800FC {
    f32 value0;
    char text4[8];
} Rodata800800FC;

const Rodata800800FC D_800800FC = {
    1000001.0f,
    "It$PIt$\000",
};
