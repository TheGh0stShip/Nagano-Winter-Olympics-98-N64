#include "types.h"

/* Initialized rodata at 0x80081020..0x80081028 (ROM 0x81C20..0x81C28); consumer: func_80054118. */
typedef struct Rodata80081020 {
    u32 word0;
    u32 word4;
} Rodata80081020;

const Rodata80081020 D_80081020 = {
    0x80000000,
    0x00000000,
};
