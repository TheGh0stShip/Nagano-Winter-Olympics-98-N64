#include "types.h"

/* Initialized data at 0x8007DA90..0x8007DAA0 (ROM 0x7E690..0x7E6A0); consumer: shared. */
typedef struct Data8007DA90 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
} Data8007DA90;

Data8007DA90 D_8007DA90 = {
    0x8007DA30,
    0x8007DA60,
    0x00000000,
    0x00000000,
};
