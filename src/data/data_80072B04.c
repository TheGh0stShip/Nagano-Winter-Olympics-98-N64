#include "types.h"

/* Initialized data at 0x80072B04..0x80072B34 (ROM 0x73704..0x73734); consumer: shared. */
typedef struct Data80072B04 {
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
} Data80072B04;

Data80072B04 D_80072B04 = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x3F800000,
    0x3F800000,
    0x3F800000,
    0x00000000,
    0x00000001,
    0x80063948,
    0x00000000,
    0x00000000,
    0x00000000,
};
