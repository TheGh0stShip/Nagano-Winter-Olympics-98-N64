#include "types.h"

/* Initialized data at 0x80073110..0x80073140 (ROM 0x73D10..0x73D40); consumer: func_80044658. */
typedef struct Data80073110 {
    u32 word0;
    f32 value4;
    u32 word8;
    f32 valueC;
    f32 value10;
    f32 value14;
    u32 word18;
    u32 word1C;
    u32 word20;
    u32 word24;
    u32 word28;
    u32 word2C;
} Data80073110;

Data80073110 D_80073110 = {
    0x00000000,
    0.0f,
    0x00000000,
    1.0f,
    1.0f,
    1.0f,
    0x09000000,
    0x00000001,
    0x80063948,
    0x00000000,
    0x00000000,
    0x00000000,
};
