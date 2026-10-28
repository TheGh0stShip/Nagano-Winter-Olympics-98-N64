#include "types.h"

/* Initialized data at 0x8006D2EC..0x8006D310 (ROM 0x6DEEC..0x6DF10); consumer: func_8000C5AC. */
typedef struct Data8006D2EC {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
} Data8006D2EC;

Data8006D2EC D_8006D2EC = {
    0x00010000,
    0x8006D2C0,
    0x06007948,
    0x06007A88,
    0x06006F48,
    0x06007AD8,
    0x00080200,
    0x00010001,
    0x01400100,
};
