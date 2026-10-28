#include "types.h"

/* Initialized data at 0x80072440..0x80072448 (ROM 0x73040..0x73048); consumer: shared. */
typedef struct Data80072440 {
    u32 word0;
    u32 word4;
} Data80072440;

Data80072440 D_80072440 = {
    0x060520E0,
    0x060520F0,
};
