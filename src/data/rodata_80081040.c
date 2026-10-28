#include "types.h"

/* Initialized rodata at 0x80081040..0x80081060 (ROM 0x81C40..0x81C60); consumer: func_80055E00. */
typedef struct Rodata80081040 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    f64 value18;
} Rodata80081040;

const Rodata80081040 D_80081040 = {
    0x80055EA8,
    0x80055EB4,
    0x80055ECC,
    0x80055ED8,
    0x80055EC0,
    0x80055EE4,
    173123.404906676,
};
