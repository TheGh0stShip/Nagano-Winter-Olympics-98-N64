#include "types.h"

/* Initialized rodata at 0x80080110..0x80080118 (ROM 0x80D10..0x80D18); consumer: func_8002A9B0. */
typedef struct Rodata80080110 {
    f32 value0;
    u32 word4;
} Rodata80080110;

const Rodata80080110 D_80080110 = {
    60000.0f,
    0x00000000,
};
