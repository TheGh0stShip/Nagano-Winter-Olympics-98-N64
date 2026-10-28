#include "types.h"

extern u8 func_800596D0[];
extern u8 func_800596EC[];

/* Initialized data at 0x800634E8..0x80063500 (ROM 0x640E8..0x64100); consumer: func_80000B20. */
typedef struct Data800634E8 {
    u32 word0;
    u32 word4;
    void *ptr8;
    void *ptrC;
    u32 word10;
    u32 word14;
} Data800634E8;

Data800634E8 D_800634E8 = {
    0x00000000,
    0x00000000,
    func_800596D0,
    func_800596EC,
    0x00000000,
    0x00000000,
};
