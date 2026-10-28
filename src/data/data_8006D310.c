#include "types.h"

/* Initialized data at 0x8006D310..0x8006D320 (ROM 0x6DF10..0x6DF20); consumer: func_8000CD60. */
typedef struct Data8006D310 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
} Data8006D310;

Data8006D310 D_8006D310 = {
    0x028001E0,
    0x01FF0000,
    0x028001E0,
    0x01FF0000,
};
