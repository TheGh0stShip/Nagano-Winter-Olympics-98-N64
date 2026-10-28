#include "types.h"

/* Initialized data at 0x800724A0..0x800724D0 (ROM 0x730A0..0x730D0); consumer: shared. */
typedef struct Data800724A0 {
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
} Data800724A0;

Data800724A0 D_800724A0 = {
    0x06040638,
    0x06040648,
    0x06040658,
    0x06040668,
    0x06040678,
    0x06040688,
    0x06040698,
    0x060406A8,
    0x060406B8,
    0x060406C8,
    0x060406D8,
    0x060406E8,
};
