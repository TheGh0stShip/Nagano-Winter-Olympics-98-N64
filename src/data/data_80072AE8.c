#include "types.h"

/* Initialized data at 0x80072AE8..0x80072AF0 (ROM 0x736E8..0x736F0); consumer: shared. */
typedef struct Data80072AE8 {
    u32 word0;
    u32 word4;
} Data80072AE8;

Data80072AE8 D_80072AE8 = {
    0x458B3000,
    0x00000007,
};
