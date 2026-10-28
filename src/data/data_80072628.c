#include "types.h"

/* Initialized data at 0x80072628..0x8007263C (ROM 0x73228..0x7323C); consumer: func_800324C0. */
typedef struct Data80072628 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
} Data80072628;

Data80072628 D_80072628 = {
    0x0600D628,
    0x06075398,
    0x060753A8,
    0x060753B8,
    0x060753C8,
};
