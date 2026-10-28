#include "types.h"

/* Initialized data at 0x8006D2C8..0x8006D2EC (ROM 0x6DEC8..0x6DEEC); consumer: func_8000C710. */
typedef struct Data8006D2C8 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
} Data8006D2C8;

Data8006D2C8 D_8006D2C8 = {
    0x00010000,
    0x8006D2C4,
    0x060079E8,
    0x06007A94,
    0x06003348,
    0x06007CE0,
    0x001E0200,
    0x00010001,
    0x01400100,
};
