#include "PR/ultratypes.h"
#include "PR/mbi.h"

void func_80015430(Gfx **list, u8 *tex, u8 *str, u8 len, int x, unsigned int y, int palette) {
    int ofs;
    u8 i;
    unsigned int col;
    int row;
    int c;


    ofs = 0;
    for (i = 0; i < len; i++) {
        c = *str++;
        if (c >= 16) {
            col = ((c - 16) & 7) * 16;
            row = ((c - 16) / 8) * 16;
            c = 0;
            gDPLoadTextureTile_4b((*list)++, tex + 0x200, G_IM_FMT_CI, 128, 0, col, row, col + 9, row + 9,
                                  palette, G_TX_WRAP, G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle((*list)++, (x + ofs) << 2, y << 2, (x + ofs + 9) << 2, (y + 9) << 2,
                                    G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);
        }
        ofs += 10;
    }
}
