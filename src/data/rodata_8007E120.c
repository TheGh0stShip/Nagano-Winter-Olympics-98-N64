#include "types.h"

/* Initialized rodata at 0x8007E120..0x8007E130 (ROM 0x7ED20..0x7ED30); consumer: func_8000CBCC. */
typedef struct Rodata8007E120 {
    f64 value0;
    u32 word8;
    u32 wordC;
} Rodata8007E120;

const Rodata8007E120 D_8007E120 = {
    0.01,
    0x00000000,
    0x00000000,
};
