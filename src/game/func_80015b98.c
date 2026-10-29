#include "PR/ultratypes.h"
#include "PR/mbi.h"

void func_80015B98(Gfx **list, void *tex, unsigned int uls, int ult, int xl, unsigned int yl, int xh, int yh, int palette) {
    gDPLoadTextureTile_4b((*list)++, tex, G_IM_FMT_CI, 128, 0, uls, ult, uls + 15, ult + 15,
                          palette, G_TX_WRAP, G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gSPScisTextureRectangle((*list)++, xl << 2, yl << 2, xh << 2, yh << 2,
                            G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);
}
