#include "types.h"

/* Initialized data at 0x80073140..0x8007314C (ROM 0x73D40..0x73D4C); consumer: shared. */
typedef struct Data80073140 {
    u32 word0;
    f32 value4;
    u32 word8;
} Data80073140;

Data80073140 D_80073140 = {
    0x00000000,
    0.0f,
    0x00000000,
};
