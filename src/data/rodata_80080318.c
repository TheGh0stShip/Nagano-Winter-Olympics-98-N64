#include "types.h"

/* Initialized rodata at 0x80080318..0x80080320 (ROM 0x80F18..0x80F20); consumer: func_80035508. */
typedef struct Rodata80080318 {
    char text0[5];
    u8 pad5[3];
} Rodata80080318;

const Rodata80080318 D_80080318 = {
    "?fff\000",
    { 0x00, 0x00, 0x00 },
};
