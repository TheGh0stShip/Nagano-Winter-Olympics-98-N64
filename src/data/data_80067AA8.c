#include "types.h"

/* Initialized data at 0x80067AA8..0x80067AC0 (ROM 0x686A8..0x686C0); consumer: shared. */
typedef struct Data80067AA8 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
} Data80067AA8;

Data80067AA8 D_80067AA8 = {
    0x090D020A,
    0x0C040F08,
    0x0B050006,
    0x0E010307,
    0x00000000,
    0x00000000,
};
