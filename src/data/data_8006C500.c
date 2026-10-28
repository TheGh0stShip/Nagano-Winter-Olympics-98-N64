#include "types.h"

/* Initialized data at 0x8006C500..0x8006C504 (ROM 0x6D100..0x6D104); consumer: shared. */
typedef struct Data8006C500 {
    u32 word0;
} Data8006C500;

Data8006C500 D_8006C500 = {
    0x01000000,
};
