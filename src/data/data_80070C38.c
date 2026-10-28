#include "types.h"

/* Initialized data at 0x80070C38..0x80070C44 (ROM 0x71838..0x71844); consumer: func_80025008. */
typedef struct Data80070C38 {
    f32 value0;
    u32 word4;
    u32 word8;
} Data80070C38;

Data80070C38 D_80070C38 = {
    7000.0f,
    0x45DAC000,
    0x45DAC000,
};
