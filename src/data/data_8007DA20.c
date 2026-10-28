#include "types.h"

/* Initialized data at 0x8007DA20..0x8007DA30 (ROM 0x7E620..0x7E630); consumer: shared. */
typedef struct Data8007DA20 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
} Data8007DA20;

Data8007DA20 D_8007DA20 = {
    0x80194240,
    0x00000000,
    0x00000000,
    0x00000000,
};
