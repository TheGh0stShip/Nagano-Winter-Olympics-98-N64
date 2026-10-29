#include "types.h"

extern f32 D_8006E600[];

f32 func_80005550(f32 y, f32 x) {
    f32 ax;
    f32 ay;
    s32 i;
    f32 r;

    ax = (x < 0.0f) ? -x : x;
    ay = (y < 0.0f) ? -y : y;
    if (x == 0.0f) {
        if (y == 0.0f) {
            r = 0.0f;
        } else if (y > 0.0f) {
            r = 1.57079637f;
        } else if (y < 0.0f) {
            r = 4.71238899f;
        }
    } else if (y == 0.0f) {
        if (x > 0.0f) {
            r = 0.0f;
        } else {
            r = 3.14159274f;
        }
    } else if (ay < ax) {
        i = (s32)(ay * 512.0 / ax);
        if ((u32)i > 512) {
            i = 512;
        }
        r = D_8006E600[i];
    } else if (ax < ay) {
        i = (s32)(ax * 512.0 / ay);
        if ((u32)i > 512) {
            i = 512;
        }
        r = 1.5707963267948966 - D_8006E600[i];
    } else if (ax == ay) {
        r = 0.785398185f;
    }
    if (x < 0.0f && y > 0.0f) {
        r = 3.141592653589793 - r;
    } else if (x < 0.0f && y < 0.0f) {
        r = r + 3.141592653589793;
    } else if (x > 0.0f && y < 0.0f) {
        r = 6.283185307179586 - r;
    }
    return r;
}
