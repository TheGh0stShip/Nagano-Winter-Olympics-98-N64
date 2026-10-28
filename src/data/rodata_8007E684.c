#include "types.h"

/* Initialized rodata at 0x8007E684..0x8007E690 (ROM 0x7F284..0x7F290); consumer: func_8001745C. */
typedef struct Rodata8007E684 {
    f32 value0;
    f32 value4;
    u32 word8;
} Rodata8007E684;

const Rodata8007E684 D_8007E684 = {
    10000.0f,
    -10000.0f,
    0x00000000,
};
