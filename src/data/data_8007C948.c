#include "types.h"

/* Initialized data at 0x8007C948..0x8007C954 (ROM 0x7D548..0x7D554); consumer: shared. */
typedef struct Data8007C948 {
    u32 word0;
    u32 word4;
    u32 word8;
} Data8007C948;

Data8007C948 D_8007C948 = {
    0x8007C940,
    0x8007C940,
    0x00000000,
};
