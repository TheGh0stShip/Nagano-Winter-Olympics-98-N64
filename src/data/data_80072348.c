#include "types.h"

/* Initialized data at 0x80072348..0x80072378 (ROM 0x72F48..0x72F78); consumer: shared. */
typedef struct Data80072348 {
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
} Data80072348;

Data80072348 D_80072348 = {
    0x060380E0,
    0x060380F0,
    0x06038100,
    0x06038110,
    0x06038120,
    0x06038130,
    0x06038140,
    0x06038150,
    0x06038160,
    0x06038170,
    0x06038180,
    0x06038190,
};
