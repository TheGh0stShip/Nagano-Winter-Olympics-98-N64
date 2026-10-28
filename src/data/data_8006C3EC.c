#include "types.h"

/* Initialized data at 0x8006C3EC..0x8006C3F4 (ROM 0x6CFEC..0x6CFF4); consumer: shared. */
typedef struct Data8006C3EC {
    u32 word0;
    u32 word4;
} Data8006C3EC;

Data8006C3EC D_8006C3EC = {
    0x00000000,
    0x00000000,
};
