#include "types.h"

/* Initialized rodata at 0x8007DE38..0x8007DE50 (ROM 0x7EA38..0x7EA50); consumer: func_80003530. */
typedef struct Rodata8007DE38 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
} Rodata8007DE38;

const Rodata8007DE38 D_8007DE38 = {
    0x80003564,
    0x80003584,
    0x800036E4,
    0x80003634,
    0x80003670,
    0x800036A0,
};
