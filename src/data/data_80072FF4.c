#include "types.h"

/* Initialized data at 0x80072FF4..0x80073024 (ROM 0x73BF4..0x73C24); consumer: shared. */
typedef struct Data80072FF4 {
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
} Data80072FF4;

Data80072FF4 D_80072FF4 = {
    0x80072C10,
    0x80072C10,
    0x80072C88,
    0x80072C88,
    0x80072D00,
    0x80072D78,
    0x80072C10,
    0x80072E20,
    0x80072E20,
    0x80072E98,
    0x80072F40,
    0x80072FE8,
};
