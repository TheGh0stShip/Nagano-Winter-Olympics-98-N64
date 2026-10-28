#include "types.h"

/* Initialized rodata at 0x8007FA18..0x8007FA30 (ROM 0x80618..0x80630); consumer: func_80021328. */
typedef struct Rodata8007FA18 {
    f64 value0;
    f64 value8;
    u32 word10;
    u32 word14;
} Rodata8007FA18;

const Rodata8007FA18 D_8007FA18 = {
    3.141592653589793,
    180.0,
    0x00000000,
    0x00000000,
};
