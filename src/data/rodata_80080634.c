#include "types.h"

/* Initialized rodata at 0x80080634..0x80080658 (ROM 0x81234..0x81258); consumer: func_80038E88. */
typedef struct Rodata80080634 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
} Rodata80080634;

const Rodata80080634 D_80080634 = {
    0x80038EF8,
    0x80038F54,
    0x80038F54,
    0x80038F54,
    0x80038F78,
    0x80038FB4,
    0x80038FB4,
    0x80038FB4,
    0x00000000,
};
