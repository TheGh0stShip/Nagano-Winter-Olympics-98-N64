#include "types.h"

/* Initialized data at 0x8007DB90..0x8007DBC0 (ROM 0x7E790..0x7E7C0); consumer: func_8005F0E0. */
typedef struct Data8007DB90 {
    char text0[17];
    u8 pad11[3];
    char text14[17];
    u8 pad25[3];
    u32 word28;
    u32 word2C;
} Data8007DB90;

Data8007DB90 D_8007DB90 = {
    "0123456789abcdef\000",
    { 0x00, 0x00, 0x00 },
    "0123456789ABCDEF\000",
    { 0x00, 0x00, 0x00 },
    0x00000000,
    0x00000000,
};
