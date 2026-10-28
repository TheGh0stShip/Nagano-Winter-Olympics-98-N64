#include "types.h"

/* Initialized rodata at 0x80080518..0x80080544 (ROM 0x81118..0x81144); consumer: func_80036FEC. */
typedef struct Rodata80080518 {
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
} Rodata80080518;

const Rodata80080518 D_80080518 = {
    0x80037024,
    0x80037024,
    0x8003701C,
    0x8003701C,
    0x80037014,
    0x8003701C,
    0x80037024,
    0x80037024,
    0x80037024,
    0x80037024,
    0x8003702C,
};
