#include "types.h"

/* Initialized data at 0x80070C0C..0x80070C2C (ROM 0x7180C..0x7182C); consumer: func_80025008. */
typedef struct Data80070C0C {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
} Data80070C0C;

Data80070C0C D_80070C0C = {
    0x00010002,
    0x00040008,
    0x00100020,
    0x00400080,
    0x01000200,
    0x04000800,
    0x10002000,
    0x40008000,
};
