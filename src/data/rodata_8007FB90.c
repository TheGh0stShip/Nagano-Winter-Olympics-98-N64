#include "types.h"

/* Initialized rodata at 0x8007FB90..0x8007FBA8 (ROM 0x80790..0x807A8); consumer: func_80023128. */
typedef struct Rodata8007FB90 {
    f64 value0;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
} Rodata8007FB90;

const Rodata8007FB90 D_8007FB90 = {
    0.2,
    0x00000000,
    0x00000000,
    0x3F50624D,
    0xD2F1A9FC,
};
