#include "types.h"

/* Initialized data at 0x8006C4C4..0x8006C4E8 (ROM 0x6D0C4..0x6D0E8); consumer: func_8000A470. */
typedef struct Data8006C4C4 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
} Data8006C4C4;

Data8006C4C4 D_8006C4C4 = {
    0x00000000,
    0xC1200000,
    0x00000000,
    0x00640000,
    0x00000007,
    0x80063958,
    0x060033F0,
    0x00000000,
    0x00000000,
};
