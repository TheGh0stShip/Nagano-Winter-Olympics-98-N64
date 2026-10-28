#include "types.h"

/* Initialized data at 0x8007264C..0x80072658 (ROM 0x7324C..0x73258); consumer: shared. */
typedef struct Data8007264C {
    u32 word0;
    u32 word4;
    u32 word8;
} Data8007264C;

Data8007264C D_8007264C = {
    0x060762B8,
    0x060762C8,
    0x060762D8,
};
