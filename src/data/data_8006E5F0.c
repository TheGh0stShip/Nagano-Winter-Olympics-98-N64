#include "types.h"

/* Initialized data at 0x8006E5F0..0x8006E600 (ROM 0x6F1F0..0x6F200); consumer: shared. */
typedef struct Data8006E5F0 {
    u32 word0;
    f32 value4;
    u32 word8;
    u32 wordC;
} Data8006E5F0;

Data8006E5F0 D_8006E5F0 = {
    0x00000003,
    45720360.0f,
    0x00000000,
    0x00000000,
};
