#include "PR/ultratypes.h"
#include "PR/mbi.h"

extern Gfx *D_80126BF4;

void func_8002F9B4(u16 count, Lights7 *lights) {
    u16 i;

    gSPNumLights(D_80126BF4++, count);
    for (i = 0; i < count; i++) {
        gSPLight(D_80126BF4++, &lights->l[i], i + 1);
    }
    gSPLight(D_80126BF4++, &lights->a, count + 1);
}
