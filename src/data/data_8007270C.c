#include "types.h"

/* Initialized data at 0x8007270C..0x80072714 (ROM 0x7330C..0x73314); consumer: shared. */
typedef struct Data8007270C {
    u32 word0;
    u32 word4;
} Data8007270C;

Data8007270C D_8007270C = {
    0x0601F9E0,
    0x0601F9F0,
};
