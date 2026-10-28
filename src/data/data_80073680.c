#include "types.h"

/* Initialized data at 0x80073680..0x80073688 (ROM 0x74280..0x74288); consumer: shared. */
typedef struct Data80073680 {
    u32 word0;
    u32 word4;
} Data80073680;

Data80073680 D_80073680 = {
    0x00000000,
    0x00000000,
};
