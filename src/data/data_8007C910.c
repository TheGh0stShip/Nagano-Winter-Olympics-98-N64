#include "types.h"

/* Initialized data at 0x8007C910..0x8007C920 (ROM 0x7D510..0x7D520); consumer: shared. */
typedef struct Data8007C910 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
} Data8007C910;

Data8007C910 D_8007C910 = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
};
