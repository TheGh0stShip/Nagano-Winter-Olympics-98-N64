#include "types.h"

/* Initialized rodata at 0x80081154..0x80081174 (ROM 0x81D54..0x81D74); consumer: func_80059D80. */
typedef struct Rodata80081154 {
    char text0[6];
    u8 pad6[2];
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
} Rodata80081154;

const Rodata80081154 D_80081154 = {
    " +-#0\000",
    { 0x00, 0x00 },
    0x00000001,
    0x00000002,
    0x00000004,
    0x00000008,
    0x00000010,
    0x00000000,
};
