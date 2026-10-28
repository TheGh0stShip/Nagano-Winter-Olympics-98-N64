#include "types.h"

/* Initialized data at 0x80071CBC..0x80071CEC (ROM 0x728BC..0x728EC); consumer: func_8002D508. */
typedef struct Data80071CBC {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
    u32 word24;
    u32 word28;
    u32 word2C;
} Data80071CBC;

Data80071CBC D_80071CBC = {
    0x06095520,
    0x060873F8,
    0x06082E88,
    0x060833B0,
    0x06069058,
    0x0604A600,
    0x06095648,
    0x0604F5F0,
    0x0604FA28,
    0x0608EA80,
    0x0608EE40,
    0x0604A2E8,
};
