#include "types.h"

/* Initialized rodata at 0x80081060..0x80081090 (ROM 0x81C60..0x81C90); consumer: func_80056A28. */
typedef struct Rodata80081060 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    f64 value20;
    u32 word28;
    u32 word2C;
} Rodata80081060;

const Rodata80081060 D_80081060 = {
    0x80056A60,
    0x80056A94,
    0x80056AF4,
    0x80056AC8,
    0x80056B20,
    0x80056B4C,
    0x80056BB4,
    0x80056C2C,
    173123.404906676,
    0x00000000,
    0x00000000,
};
