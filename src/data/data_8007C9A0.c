#include "types.h"

/* Initialized data at 0x8007C9A0..0x8007C9B0 (ROM 0x7D5A0..0x7D5B0); consumer: shared. */
typedef struct Data8007C9A0 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
} Data8007C9A0;

Data8007C9A0 D_8007C9A0 = {
    0x003FFF01,
    0x00000000,
    0x00000000,
    0x00000000,
};
