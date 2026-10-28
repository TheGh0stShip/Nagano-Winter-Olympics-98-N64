#include "types.h"

/* Initialized rodata at 0x800812B0..0x800812C0 (ROM 0x81EB0..0x81EC0); consumer: shared. */
typedef struct Rodata800812B0 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
} Rodata800812B0;

const Rodata800812B0 D_800812B0 = {
    0x7F810000,
    0x00000000,
    0x00000000,
    0x00000000,
};
