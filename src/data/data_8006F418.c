#include "types.h"

/* Initialized data at 0x8006F418..0x8006F440 (ROM 0x70018..0x70040); consumer: func_8001AB58. */
typedef struct Data8006F418 {
    char text0[6];
    u8 pad6[2];
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    u32 word18;
    u32 word1C;
    u32 word20;
    u32 word24;
} Data8006F418;

Data8006F418 D_8006F418 = {
    "dP2(d\000",
    { 0x00, 0x00 },
    0x8006F340,
    0x8006F378,
    0x8006F3A4,
    0x8006F3C4,
    0x8006F3DC,
    0x000000FF,
    0x00000000,
    0x00000000,
};
