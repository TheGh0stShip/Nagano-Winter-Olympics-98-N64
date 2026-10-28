#include "types.h"

/* Initialized rodata at 0x8007EE18..0x8007EE38 (ROM 0x7FA18..0x7FA38); consumer: func_8001F8B4. */
typedef struct Rodata8007EE18 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
} Rodata8007EE18;

const Rodata8007EE18 D_8007EE18 = {
    0x8001F8FC,
    0x8001F95C,
    0x8001F90C,
    0x8001F95C,
    0x8001F91C,
    0x8001F92C,
    0x8001F93C,
    0x8001F950,
};
