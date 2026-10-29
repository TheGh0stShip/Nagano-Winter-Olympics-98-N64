#include "PR/ultratypes.h"
#include "PR/mbi.h"

void func_8001577C(Gfx **list, u8 *tex, u16 value, int x, unsigned int y, int palette) {
    u16 digits[3];
    u8 i;
    unsigned int col;
    int row;

    digits[0] = value / 100;
    digits[1] = (value / 10) % 10;
    digits[2] = value % 10;
    i = 0;
    if (digits[0] == 0) {
        i = 1;
    }
    if (digits[0] == 0 && digits[1] == 0) {
        i = 2;
    }
    for (; i < 3; i++) {
        col = (digits[i] & 7) * 16;
        row = (digits[i] / 8) * 16;
        gDPLoadTextureTile_4b((*list)++, tex + 0x200, G_IM_FMT_CI, 128, 0, col, row, col + 9, row + 9,
                              palette, G_TX_WRAP, G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle((*list)++, (i * 10 + x) << 2, y << 2, (i * 10 + x + 9) << 2, (y + 9) << 2,
                                G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);
    }
}
