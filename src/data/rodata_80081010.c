#include "types.h"

/* Initialized rodata at 0x80081010..0x80081020 (ROM 0x81C10..0x81C20); consumer: func_80051E90. */
typedef struct Rodata80081010 {
    f64 value0;
    u32 word8;
    u32 wordC;
} Rodata80081010;

const Rodata80081010 D_80081010 = {
    0.017453292222222222,
    0x00000000,
    0x00000000,
};
