#include "types.h"

/* Initialized data at 0x80072B64..0x80072BA4 (ROM 0x73764..0x737A4); consumer: shared. */
typedef struct Data80072B64 {
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
    u32 word30;
    u32 word34;
    u32 word38;
    u32 word3C;
} Data80072B64;

Data80072B64 D_80072B64 = {
    0x06010EE8,
    0x06010EF8,
    0x06010F08,
    0x06010F18,
    0x06010F28,
    0x06010F38,
    0x06010F48,
    0x06010F58,
    0x06010F68,
    0x06010F78,
    0x06010F88,
    0x06010F98,
    0x06010FA8,
    0x06010FB8,
    0x06010FC8,
    0x06010FD8,
};
