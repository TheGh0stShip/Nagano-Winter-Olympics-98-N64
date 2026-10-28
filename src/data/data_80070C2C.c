#include "types.h"

/* Initialized data at 0x80070C2C..0x80070C38 (ROM 0x7182C..0x71838); consumer: func_80024560. */
typedef struct Data80070C2C {
    f32 value0;
    u32 word4;
    u32 word8;
} Data80070C2C;

Data80070C2C D_80070C2C = {
    5000.0f,
    0x457A0000,
    0x457A0000,
};
