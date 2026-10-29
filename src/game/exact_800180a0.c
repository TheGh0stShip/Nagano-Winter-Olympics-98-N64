#include "PR/ultratypes.h"
#include "PR/mbi.h"

extern Gfx *D_80126BF4;
extern void *D_8006F220[];
extern unsigned int func_80005E18(void *arg, void *texture);

void func_800180A0(void *arg, int unused, unsigned short index, float x, float y) {
    int sx, sy;

    x -= 5.0f;
    y -= 6.0f;
    sy = (short)y;
    sx = (short)x;
    unused = func_80005E18(arg, D_8006F220[index]);
    gDPPipeSync(D_80126BF4++);
    gDPLoadTextureBlock(D_80126BF4++, unused, G_IM_FMT_CI, G_IM_SIZ_8b, 16, 16, 0, G_TX_CLAMP, G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPPipeSync(D_80126BF4++);
    gSPScisTextureRectangle(D_80126BF4++, sx << 2, sy << 2, (sx + 9) << 2, (sy + 11) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
}
