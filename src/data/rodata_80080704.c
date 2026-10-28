#include "types.h"

/* Initialized rodata at 0x80080704..0x80080720 (ROM 0x81304..0x81320); consumer: func_8003C6B4. */
typedef struct Rodata80080704 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
} Rodata80080704;

const Rodata80080704 D_80080704 = {
    0x8003C6F4,
    0x8003C708,
    0x8003C744,
    0x8003C71C,
    0x8003C730,
    0x8003C71C,
    0x8003C730,
};
