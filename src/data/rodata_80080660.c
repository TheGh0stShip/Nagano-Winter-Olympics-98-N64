#include "types.h"

/* Initialized rodata at 0x80080660..0x80080698 (ROM 0x81260..0x81298); consumer: func_80039788. */
typedef struct Rodata80080660 {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
    u32 word10;
    u32 word14;
    f64 value18;
    char text20[5];
    u8 pad25[3];
    f64 value28;
    f32 value30;
    u32 word34;
} Rodata80080660;

const Rodata80080660 D_80080660 = {
    0x80039844,
    0x80039864,
    0x80039854,
    0x80039854,
    0x80039854,
    0x80039844,
    0.047123891676382035,
    "@q7L\000",
    { 0x00, 0x00, 0x00 },
    1.5707963267948966,
    1.57079637f,
    0x00000000,
};
