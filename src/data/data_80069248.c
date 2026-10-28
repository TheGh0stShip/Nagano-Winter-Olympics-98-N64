#include "types.h"

/* Initialized data at 0x80069248..0x80069260 (ROM 0x69E48..0x69E60); consumer: shared. */
typedef struct Data80069248 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
} Data80069248;

Data80069248 D_80069248 = {
    0x00000000,
    0x00000001,
    0x00000001,
    0x00000000,
    0x00000000,
    0x00000000,
};
