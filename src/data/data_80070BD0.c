#include "types.h"

/* Initialized data at 0x80070BD0..0x80070C00 (ROM 0x717D0..0x71800); consumer: func_80025008. */
typedef struct Data80070BD0 {
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
    u32 word28;
    u32 word2C;
} Data80070BD0;

Data80070BD0 D_80070BD0 = {
    0x0608F400,
    0x060808AC,
    0x0608F4C4,
    0x0608F430,
    0x060808C8,
    0x0608F4DC,
    0x0608F460,
    0x060808E4,
    0x0608F4F4,
    0x0608F490,
    0x06080900,
    0x0608F50C,
};
