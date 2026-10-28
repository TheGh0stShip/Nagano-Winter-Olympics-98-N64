#include "types.h"

/* Initialized data at 0x8006F7B4..0x8006F7C0 (ROM 0x703B4..0x703C0); consumer: func_8001C630. */
typedef struct Data8006F7B4 {
    char text0[10];
    u8 padA[2];
} Data8006F7B4;

Data8006F7B4 D_8006F7B4 = {
    "00:00:000\000",
    { 0x00, 0x00 },
};
