#include "types.h"

/* Initialized data at 0x80063500..0x80063514 (ROM 0x64100..0x64114); consumer: shared. */
typedef struct Data80063500 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
} Data80063500;

Data80063500 D_80063500 = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
};
