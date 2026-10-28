#include "types.h"

/* Initialized rodata at 0x80081310..0x80081318 (ROM 0x81F10..0x81F18); consumer: func_8005E490. */
typedef struct Rodata80081310 {
    u32 word0;
    u32 word4;
} Rodata80081310;

const Rodata80081310 D_80081310 = {
    0x30000000,
    0x00000000,
};
