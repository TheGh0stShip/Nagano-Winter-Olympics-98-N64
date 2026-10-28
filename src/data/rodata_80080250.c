#include "types.h"

/* Initialized rodata at 0x80080250..0x80080264 (ROM 0x80E50..0x80E64); consumer: func_8003070C. */
typedef struct Rodata80080250 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
} Rodata80080250;

const Rodata80080250 D_80080250 = {
    0x80030740,
    0x800307E0,
    0x80030790,
    0x8003082C,
    0x80030870,
};
