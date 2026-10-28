#include "types.h"

/* Initialized data at 0x80072AD0..0x80072AE4 (ROM 0x736D0..0x736E4); consumer: shared. */
typedef struct Data80072AD0 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
} Data80072AD0;

Data80072AD0 D_80072AD0 = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x80080350,
};
