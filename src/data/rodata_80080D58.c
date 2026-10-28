#include "types.h"

/* Initialized rodata at 0x80080D58..0x80080D70 (ROM 0x81958..0x81970); consumer: func_80046928. */
typedef struct Rodata80080D58 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
} Rodata80080D58;

const Rodata80080D58 D_80080D58 = {
    0x80046A9C,
    0x80046958,
    0x80046A9C,
    0x800469FC,
    0x80046A9C,
    0x00000000,
};
