#include "types.h"

/* Initialized rodata at 0x8007DCA4..0x8007DCB8 (ROM 0x7E8A4..0x7E8B8); consumer: func_80002188. */
typedef struct Rodata8007DCA4 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
} Rodata8007DCA4;

const Rodata8007DCA4 D_8007DCA4 = {
    0x800021BC,
    0x80002318,
    0x8000236C,
    0x8000234C,
    0x800024C8,
};
