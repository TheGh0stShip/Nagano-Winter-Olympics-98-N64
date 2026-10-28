#include "types.h"

/* Initialized data at 0x80070CB8..0x80070CC0 (ROM 0x718B8..0x718C0); consumer: shared. */
typedef struct Data80070CB8 {
    u32 word0;
    u32 word4;
} Data80070CB8;

Data80070CB8 D_80070CB8 = {
    0x0101FFFF,
    0xFFFF0000,
};
