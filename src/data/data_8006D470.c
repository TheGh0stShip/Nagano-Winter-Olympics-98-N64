#include "types.h"

/* Initialized data at 0x8006D470..0x8006D47A (ROM 0x6E070..0x6E07A); consumer: shared. */
typedef struct Data8006D470 {
    char text0[9];
    u8 pad9[1];
} Data8006D470;

/* Initialized data at 0x8006D47A..0x8006D47C (ROM 0x6E07A..0x6E07C); consumer: func_8002B014. */
typedef struct Data8006D47A {
    u8 pad0[2];
} Data8006D47A;

/* D_8006D470 groups objects that start mid-word; inner symbols:
 * D_8006D47A = D_8006D470 + 0xa
 */
typedef struct Group8006D470 {
    Data8006D470 o8006D470;
    Data8006D47A o8006D47A;
} Group8006D470;

Group8006D470 D_8006D470 = {
    {
        "N.Trails\000",
        { 0x00 },
    },
    {
        { 0x0C, 0x00 },
    }
};
