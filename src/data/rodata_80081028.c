#include "types.h"

/* Initialized rodata at 0x80081028..0x80081030 (ROM 0x81C28..0x81C30); consumer: func_800541B8. */
typedef struct Rodata80081028 {
    u32 word0;
    u32 word4;
} Rodata80081028;

const Rodata80081028 D_80081028 = {
    0x80000000,
    0x00000000,
};
