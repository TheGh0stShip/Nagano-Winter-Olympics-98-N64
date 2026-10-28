#include "types.h"

/* Initialized rodata at 0x8007E130..0x8007E140 (ROM 0x7ED30..0x7ED40); consumer: func_8000DAC0. */
typedef struct Rodata8007E130 {
    char text0[14];
    u8 padE[2];
} Rodata8007E130;

const Rodata8007E130 D_8007E130 = {
    "No Controller\000",
    { 0x00, 0x00 },
};
