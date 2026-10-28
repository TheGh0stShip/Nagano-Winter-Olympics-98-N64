#include "types.h"

/* Initialized rodata at 0x8007E320..0x8007E338 (ROM 0x7EF20..0x7EF38); consumer: func_8000FB24. */
typedef struct Rodata8007E320 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
} Rodata8007E320;

const Rodata8007E320 D_8007E320 = {
    0x8000FB6C,
    0x8000FBB0,
    0x8000FC34,
    0x8000FC54,
    0x8000FC8C,
    0x8000FBE4,
};
