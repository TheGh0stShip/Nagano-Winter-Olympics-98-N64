#include "types.h"

/* Initialized rodata at 0x80081030..0x80081038 (ROM 0x81C30..0x81C38); consumer: func_800553C8. */
typedef struct Rodata80081030 {
    char text0[5];
    u8 pad5[3];
} Rodata80081030;

const Rodata80081030 D_80081030 = {
    "A.\204\200\000",
    { 0x00, 0x00, 0x00 },
};
