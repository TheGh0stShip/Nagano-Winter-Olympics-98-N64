#include "types.h"

/* Initialized data at 0x80072538..0x80072540 (ROM 0x73138..0x73140); consumer: shared. */
typedef struct Data80072538 {
    u32 word0;
    u32 word4;
} Data80072538;

Data80072538 D_80072538 = {
    0x06025D50,
    0x06025D60,
};
