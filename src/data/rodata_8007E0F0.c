#include "types.h"

/* Initialized rodata at 0x8007E0F0..0x8007E108 (ROM 0x7ECF0..0x7ED08); consumer: func_8000C484. */
typedef struct Rodata8007E0F0 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
} Rodata8007E0F0;

const Rodata8007E0F0 D_8007E0F0 = {
    0x8000C4B8,
    0x8000C4EC,
    0x8000C51C,
    0x8000C53C,
    0x8000C568,
    0x8000C578,
};
