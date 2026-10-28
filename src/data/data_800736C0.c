#include "types.h"

/* Initialized data at 0x800736C0..0x800736DC (ROM 0x742C0..0x742DC); consumer: func_80048080. */
typedef struct Data800736C0 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
} Data800736C0;

Data800736C0 D_800736C0 = {
    0x80076454,
    0x80078364,
    0x8007A768,
    0x8007C324,
    0x00000001,
    0x00002EE0,
    0x00000000,
};
