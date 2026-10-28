#include "types.h"

/* Initialized data at 0x8007C960..0x8007C970 (ROM 0x7D560..0x7D570); consumer: shared. */
typedef struct Data8007C960 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
} Data8007C960;

Data8007C960 D_8007C960 = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
};
