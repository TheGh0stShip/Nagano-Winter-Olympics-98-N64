#include "types.h"

/* Initialized data at 0x800731D0..0x800731FC (ROM 0x73DD0..0x73DFC); consumer: func_800448B4. */
typedef struct Data800731D0 {
    u32 word0;
    u32 word4;
    f32 value8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
    u32 word24;
    u32 word28;
} Data800731D0;

Data800731D0 D_800731D0 = {
    0x80073170,
    0x800731A0,
    167.5f,
    0x43428000,
    0x432F8000,
    0x0307050F,
    0x0A0E01FF,
    0x0E00010A,
    0x05FF0000,
    0x070E0A00,
    0x04FF0000,
};
