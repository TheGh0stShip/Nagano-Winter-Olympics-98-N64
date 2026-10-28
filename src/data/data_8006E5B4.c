#include "types.h"

extern u8 func_8001E810[];

/* Initialized data at 0x8006E5B4..0x8006E5E4 (ROM 0x6F1B4..0x6F1E4); consumer: func_80011C3C. */
typedef struct Data8006E5B4 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
    u32 word24;
    void *ptr28;
    u32 word2C;
} Data8006E5B4;

Data8006E5B4 D_8006E5B4 = {
    0x801954A0,
    0x801954C0,
    0x801954A0,
    0x8019A90C,
    0x801954A0,
    0x801954A0,
    0x801954E0,
    0x801954A0,
    0x801A0DB4,
    0x801954A0,
    func_8001E810,
    0x801954A0,
};
