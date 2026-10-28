#include "types.h"

/* Initialized data at 0x8007C980..0x8007C99C (ROM 0x7D580..0x7D59C); consumer: shared. */
typedef struct Data8007C980 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
} Data8007C980;

Data8007C980 D_8007C980 = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x03B9ACA0,
    0x02E6D354,
};
