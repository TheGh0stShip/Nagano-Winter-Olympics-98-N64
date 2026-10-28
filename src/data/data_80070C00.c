#include "types.h"

/* Initialized data at 0x80070C00..0x80070C0C (ROM 0x71800..0x7180C); consumer: shared. */
typedef struct Data80070C00 {
    u32 word0;
    u32 word4;
    u32 word8;
} Data80070C00;

Data80070C00 D_80070C00 = {
    0x00000015,
    0x00000016,
    0x0000001B,
};
