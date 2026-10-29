#include "PR/ultratypes.h"
#include "PR/mbi.h"

extern void func_80015E24();

void func_800160B4(Gfx **list, void *tex, unsigned int s, int t, int xl, int yl, int xh, int yh, int palette) {
    unsigned int i;
    unsigned int j;
    unsigned int cols;
    unsigned int rows;
    unsigned int width;

    width = xh - xl + 1;
    cols = width >> 5;
    rows = (unsigned int)(yh - yl + 1) >> 5;

    if (cols != 0 && rows != 0) {
        for (j = 0; j < rows; j++) {
            for (i = 0; i < cols; i++) {
                func_80015E24(list, tex, i * 32 + s, j * 32 + t, i * 32 + xl, j * 32 + yl,
                              i * 32 + xl + 31, j * 32 + yl + 31, palette);
            }
        }
    }
    if ((width & 0x1F) != 0 && rows != 0) {
        for (j = 0; j < rows; j++) {
            func_80015E24(list, tex, cols * 32 + s, j * 32 + t, cols * 32 + xl, j * 32 + yl,
                          cols * 32 + xl + (width & 0x1F) - 1, j * 32 + yl + 31, palette);
        }
    }
    if (((unsigned int)(yh - yl + 1) & 0x1F) != 0 && cols != 0) {
        for (i = 0; i < cols; i++) {
            func_80015E24(list, tex, i * 32 + s, rows * 32 + t, i * 32 + xl, rows * 32 + yl,
                          i * 32 + xl + 31,
                          (rows * 32 + yl | 0) + ((unsigned int)(yh - yl + 1) & 0x1F) - 1, palette);
        }
    }
    if ((width & 0x1F) != 0 && ((unsigned int)(yh - yl + 1) & 0x1F) != 0) {
        int x;
        func_80015E24(list, tex, cols * 32 + s, rows * 32 + t, cols * 32 + xl, rows * 32 + yl,
                      cols * 32 + xl + (width & 0x1F) - 1,
                      rows * 32 + yl + ((unsigned int)(yh - yl + 1) & 0x1F) - 1, palette);
    }
}
