#include "types.h"

/* Initialized data at 0x8007D9D0..0x8007DA20 (ROM 0x7E5D0..0x7E620); consumer: func_80059D80. */
typedef struct Data8007D9D0 {
    char text0[33];
    u8 pad21[3];
    char text24[33];
    u8 pad45[3];
    u32 word48;
    u32 word4C;
} Data8007D9D0;

Data8007D9D0 D_8007D9D0 = {
    "                                \000",
    { 0x00, 0x00, 0x00 },
    "00000000000000000000000000000000\000",
    { 0x00, 0x00, 0x00 },
    0x00000000,
    0x00000000,
};
