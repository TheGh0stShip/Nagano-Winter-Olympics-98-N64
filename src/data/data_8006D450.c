#include "types.h"

/* Initialized data at 0x8006D450..0x8006D458 (ROM 0x6E050..0x6E058); consumer: shared. */
typedef struct Data8006D450 {
    u32 word0;
    u32 word4;
} Data8006D450;

Data8006D450 D_8006D450 = {
    0x00000000,
    0x00000000,
};
