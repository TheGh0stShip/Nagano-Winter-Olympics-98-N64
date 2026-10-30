#define _LANGUAGE_C 1
#include "PR/ultratypes.h"
#include "PR/mbi.h"
#include "PR/gbi.h"
typedef struct {
    char pad0[4];
    unsigned char *map;
    unsigned short *tiles;
    unsigned short *pal;
    int base;
    char pad14[6];
    unsigned char mode;
    short mapw;
    short maph;
    short tw;
    short th;
} Bg;
extern Gfx *D_8013356C;

void func_8000D218(Bg *bg) {
    char p0[4];
    int row;
    int col;
    int x0;
    int x1;
    int tx;
    int t;
    int p;
    short tw;
    short mw;
    int th;
    char pa[0x14];
    int last;
    char pb[4];
    int y0;
    char pc[4];
    int y1;
    char pd[4];
    int ty;
    unsigned char *map;
    unsigned short *tiles;
    int lim;
    int mp;
    int my;
    int ox;
    int oy;
    int cx;
    int n;
    char pe[0x28];

    t = 0;
    map = bg->map;
    tiles = bg->tiles;
    last = 0xFFFF;
    lim = 0xFFFF;
    row = 0; do {
        if (row < 0) {
        } else if (row > lim) {
        } else {
            y0 = (unsigned)(row << 5);
            y1 = y0 + 31;
            ty = 0;
            if ((row << 5) < 233 && y1 >= 8) {
                if ((row << 5) < 8) {
                    ty = 8 - y0;
                    y0 = 8;
                }
                if (y1 >= 233) {
                    y1 = 232;
                }
                col = 0;
                y0 *= 4;
                y1 *= 4;
                ty <<= 5;
                do {
                    if (col >= 0) {
                        if (col <= lim) {
                            x0 = (tx = 0, ox = (int)(unsigned)(col << 5));
                            x1 = ox + 31;
                            if (ox >= 313) {
                            } else if (x1 < 8) {
                            } else {
                                if (tx + (int)(((unsigned)(y1) & 4095) << 0) * 0 + (int)(((unsigned)(y0) & 4095) << 0) * 0 + (int)(((unsigned)(ty) & 65535) << 0) * 0 + (int)(char *)(col << 5) * 0) {}
                                cx = (int)(char *)(col << 5);
                                p = (int)(char *)(row << 5);
                                if (cx) {}
                                if (ox < 8) {
                                    tx = 8 - ox;
                                    x0 = 8;
                                }
                                if (x1 + x1 * 0 >= 313) {
                                    x1 = 312;
                                }
                                x0 *= 4;
                                x1 *= 4;
                                tx <<= 5;
                                if (x0 + x1 * 0) {}
                                tw = bg->tw;
                                mw = bg->mapw;
                                mp = cx / tw; cx = (int)(char *)(col << 5); mp %= mw;
                                if (mp) {}
                                th = bg->th; if (th) {}
                                my = p / th; p = p ^ 0; my %= bg->maph;
                                if (my) {}
                                ox = (cx % (tw + tw * 0 + tw * 2 * 0 + tw * 3 * 0)) / 32;
                                oy = ((int)(char *)(row << 5) % th + ox * 0) / 32;
                                if ((((int)(char *)(row << 5)) | tw) * 0 + (((int)(char *)(row << 5)) & tw) * 0 + (((int)(char *)(row << 5)) & cx) * 0 + (((int)(char *)(row << 5)) + cx) * 0 + (cx - ((int)(char *)(row << 5))) * 0) {}
                                n = ((unsigned char *)map)[(mp + mp * 0 + mp * 2 * 0 + mp * 3 * 0 + mp * 4 * 0 + mp * 5 * 0 + mp * 6 * 0 + mp * 7 * 0) + (mw + (mw >> 1) * 0 + (mw << 1) * 0 + (mw >> 2) * 0 + (mw << 2) * 0) * (my + my * 0)];
                                if (mw) {}
                                t = *(tiles + (tw / 32) * n * (th / 32) + ox + (tw / 32) * oy + (((int)(char *)(row << 5)) - cx) * 0);
                                if (t != last) {
                                    last = t;
                                    switch (bg->mode) {
                                    case 0:
                                        gDPLoadTextureBlock(D_8013356C++, bg->base + ((t << 10) / 4) * 2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                                            G_TX_MIRROR, G_TX_MIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
                                        break;
                                    case 1:
                                        p = (bg->pal[t] & 0xF00) * 8 + ((bg->pal[t] & 0xFF) << 7);
                                        gDPLoadTextureBlock(D_8013356C++, bg->base + p * 8, G_IM_FMT_CI, G_IM_SIZ_8b, 32, 32, 0,
                                                            G_TX_MIRROR, G_TX_MIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
                                        break;
                                    case 2:
                                        p = (bg->pal[t] & 0xF00) * 4 + ((bg->pal[t] & 0xFF) << 6);
                                        gDPLoadTextureBlock_4b(D_8013356C++, bg->base + p * 8, G_IM_FMT_CI, 32, 32, 0,
                                                               G_TX_MIRROR, G_TX_MIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
                                        break;
                                    }
                                }
                                gSPTextureRectangle(D_8013356C++, x0, y0, x1, y1, G_TX_RENDERTILE, tx, ty, 4 << 10, 1 << 10);
                            }
                        }
                    }
                    col++;
                } while (col != 11);
            }
        }
    } while ((row = row + 1) != 9);
}
