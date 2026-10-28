#include "types.h"

/* Initialized data at 0x8006F7A8..0x8006F7B4 (ROM 0x703A8..0x703B4); consumer: func_8001C444. */
typedef struct Data8006F7A8 {
    char text0[10];
    u8 padA[2];
} Data8006F7A8;

Data8006F7A8 D_8006F7A8 = {
    "00:00:000\000",
    { 0x00, 0x00 },
};
