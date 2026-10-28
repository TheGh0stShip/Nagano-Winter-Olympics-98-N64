#include "types.h"

/* Initialized data at 0x80072AF4..0x80072B00 (ROM 0x736F4..0x73700); consumer: shared. */
typedef struct Data80072AF4 {
    u32 word0;
    u32 word4;
    u32 word8;
} Data80072AF4;

Data80072AF4 D_80072AF4 = {
    0x000000FF,
    0x00000000,
    0x00000000,
};
