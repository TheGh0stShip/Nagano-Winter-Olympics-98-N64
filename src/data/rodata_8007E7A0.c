#include "types.h"

/* Initialized rodata at 0x8007E7A0..0x8007E7B0 (ROM 0x7F3A0..0x7F3B0); consumer: func_8001CD08. */
typedef struct Rodata8007E7A0 {
    char text0[11];
    u8 padB[1];
    u32 wordC;
} Rodata8007E7A0;

const Rodata8007E7A0 D_8007E7A0 = {
    "0000000000\000",
    { 0x00 },
    0x00000000,
};
