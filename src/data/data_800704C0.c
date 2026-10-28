#include "types.h"

/* Initialized data at 0x800704C0..0x800704D0 (ROM 0x710C0..0x710D0); consumer: func_80020F20. */
typedef struct Data800704C0 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
} Data800704C0;

Data800704C0 D_800704C0 = {
    0x0A0A0500,
    0x00000000,
    0x00000000,
    0x00000000,
};
