#include "types.h"

/* Initialized data at 0x8006C3F4..0x8006C400 (ROM 0x6CFF4..0x6D000); consumer: func_8000840C. */
typedef struct Data8006C3F4 {
    u32 word0;
    u32 word4;
    u32 word8;
} Data8006C3F4;

Data8006C3F4 D_8006C3F4 = {
    0x05000000,
    0x00000000,
    0x00000000,
};
