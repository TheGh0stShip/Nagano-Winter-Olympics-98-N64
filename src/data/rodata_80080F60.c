#include "types.h"

/* Initialized rodata at 0x80080F60..0x80080F70 (ROM 0x81B60..0x81B70); consumer: func_8004E7E0. */
typedef struct Rodata80080F60 {
    char text0[5];
    u8 pad5[3];
    u32 word8;
    u32 wordC;
} Rodata80080F60;

const Rodata80080F60 D_80080F60 = {
    "<\216\3725\000",
    { 0x00, 0x00, 0x00 },
    0x00000000,
    0x00000000,
};
