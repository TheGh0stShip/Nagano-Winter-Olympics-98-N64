#include "types.h"

/* Initialized data at 0x80063668..0x80063698 (ROM 0x64268..0x64298); consumer: shared. */
typedef struct Data80063668 {
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
} Data80063668;

Data80063668 D_80063668 = {
    0x000DA200,
    0x801954A0,
    0x000DFB40,
    0x000DA200,
    0x40000015,
    0x00000000,
    0x40000016,
    0x00000000,
    0x40000017,
    0x00000000,
    0x40000018,
    0x00000000,
};
