#include "types.h"

/* Initialized rodata at 0x8007E108..0x8007E120 (ROM 0x7ED08..0x7ED20); consumer: func_8000C710. */
typedef struct Rodata8007E108 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
} Rodata8007E108;

const Rodata8007E108 D_8007E108 = {
    0x8000C7A0,
    0x8000C7F4,
    0x8000C8AC,
    0x8000C948,
    0x8000C9B0,
    0x8000CA10,
};
