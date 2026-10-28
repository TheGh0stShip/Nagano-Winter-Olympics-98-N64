#include "types.h"

/* Initialized data at 0x8006F640..0x8006F645 (ROM 0x70240..0x70245); consumer: shared. */
typedef struct Data8006F640 {
    u32 word0;
    u8 tail4[1];
} Data8006F640;

Data8006F640 D_8006F640 = {
    0x00000000,
    { 0x00 },
};
