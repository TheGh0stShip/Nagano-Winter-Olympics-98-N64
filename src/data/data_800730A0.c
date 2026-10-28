#include "types.h"

/* Initialized data at 0x800730A0..0x800730B0 (ROM 0x73CA0..0x73CB0); consumer: shared. */
typedef struct Data800730A0 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
} Data800730A0;

Data800730A0 D_800730A0 = {
    0x80080840,
    0x80080854,
    0x00000000,
    0x01000000,
};
