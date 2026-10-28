#include "types.h"

/* Initialized rodata at 0x80081038..0x80081040 (ROM 0x81C38..0x81C40); consumer: func_80055508. */
typedef struct Rodata80081038 {
    char text0[5];
    u8 pad5[3];
} Rodata80081038;

const Rodata80081038 D_80081038 = {
    "A.\204\200\000",
    { 0x00, 0x00, 0x00 },
};
