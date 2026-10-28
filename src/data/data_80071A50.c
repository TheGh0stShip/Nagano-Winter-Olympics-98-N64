#include "types.h"

/* Initialized data at 0x80071A50..0x80071A74 (ROM 0x72650..0x72674); consumer: shared. */
typedef struct Data80071A50 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
} Data80071A50;

Data80071A50 D_80071A50 = {
    0x0101FFFF,
    0xFFFF0101,
    0x010101FF,
    0x06FFFF03,
    0x04020001,
    0xFF05FFFF,
    0x01010202,
    0x02010102,
    0x01010101,
};
