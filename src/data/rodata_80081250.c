#include "types.h"

/* Initialized rodata at 0x80081250..0x80081260 (ROM 0x81E50..0x81E60); consumer: func_8005AE70. */
typedef struct Rodata80081250 {
    char text0[5];
    u8 pad5[3];
    u32 word8;
    u32 wordC;
} Rodata80081250;

const Rodata80081250 D_80081250 = {
    "<\216\3725\000",
    { 0x00, 0x00, 0x00 },
    0x00000000,
    0x00000000,
};
