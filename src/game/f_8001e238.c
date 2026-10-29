typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Bitmap {
    short x;
    short y;
    short width;
    short height;
    unsigned char masks;
    unsigned char maskt;
    unsigned char padA[2];
    void *texels;
} Bitmap;

typedef struct Sprite {
    void *tlut;
    Bitmap *bitmaps;
} Sprite;

typedef struct RuntimeRecord {
    unsigned char pad0[0xC];
    float x;
    float y;
    unsigned char pad14[0x118];
    Gfx *gfx;
    unsigned char pad130[0x18];
} RuntimeRecord;

#define SHIFTL(v, s, w) ((unsigned int)(((unsigned int)(v) & ((0x01 << (w)) - 1)) << (s)))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << 11) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))
#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }
#define SET_TILE(fmt, siz, line, tmem, tile, pal, cmt, maskt, shiftt, cms, masks, shifts)                         \
    GFX(0xF5000000 | SHIFTL(fmt, 21, 3) | SHIFTL(siz, 19, 2) | SHIFTL(line, 9, 9) | SHIFTL(tmem, 0, 9),          \
        SHIFTL(tile, 24, 3) | SHIFTL(pal, 20, 4) | SHIFTL(cmt, 18, 2) | SHIFTL(maskt, 14, 4) |                   \
            SHIFTL(shiftt, 10, 4) | SHIFTL(cms, 8, 2) | SHIFTL(masks, 4, 4) | SHIFTL(shifts, 0, 4))
#define TEX_RECT(xl, yl, xh, yh, tile, s, t, dsdx, dtdy)                                                          \
    {                                                                                                         \
        Gfx *_g = D_80126BF4++;                                                                               \
        _g->w0 = 0xE4000000 | SHIFTL(MAX((short)(xh), 0), 12, 12) | SHIFTL(MAX((short)(yh), 0), 0, 12);         \
        _g->w1 = SHIFTL(tile, 24, 3) | SHIFTL(MAX((short)(xl), 0), 12, 12) | SHIFTL(MAX((short)(yl), 0), 0, 12); \
        GFX(0xB4000000,                                                                                       \
            SHIFTL((s) - (((short)(xl) < 0) ? (((short)(dsdx) < 0) ? MAX((((short)(xl) * (short)(dsdx)) >> 7), 0)  \
                                                                    : MIN((((short)(xl) * (short)(dsdx)) >> 7), 0)) \
                                            : 0), 16, 16) |                                                    \
                SHIFTL((t) - (((yl) < 0) ? (((short)(dtdy) < 0) ? MAX((((short)(yl) * (short)(dtdy)) >> 7), 0)     \
                                                                : MIN((((short)(yl) * (short)(dtdy)) >> 7), 0))     \
                                         : 0), 0, 16));                                                        \
        GFX(0xB3000000, SHIFTL(dsdx, 16, 16) | SHIFTL(dtdy, 0, 16));                                            \
    }

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern Gfx D_8006FB88[];

void func_8001E238(int index, int width, int height, Sprite *sprite) {
    RuntimeRecord *record = (RuntimeRecord *)(D_80126BF0 + 0x8B2C0) + index;
    Bitmap *bitmap;
    int x;
    int y;

    x = record->x + 160.0f - 12.0f;
    y = 240.0f - (record->y + 120.0f);
    record->gfx = D_80126BF4;
    bitmap = sprite->bitmaps;
    GFX(0x06000000, (unsigned int)D_8006FB88);
    GFX(0xFD100000, (unsigned int)sprite->tlut);
    GFX(0xE8000000, 0);
    SET_TILE(0, 0, 0, 256, 7, 0, 0, 0, 0, 0, 0, 0);
    GFX(0xE6000000, 0);
    GFX(0xF0000000, SHIFTL(7, 24, 3) | SHIFTL(255, 14, 10));
    GFX(0xE7000000, 0);
loop:
    if (bitmap->width != 0) {
        GFX(0xFD500000, (unsigned int)bitmap->texels);
        SET_TILE(2, 2, 0, 0, 7, 0, 1, bitmap->maskt, 0, 2, bitmap->masks, 0);
        GFX(0xE6000000, 0);
        GFX(0xF3000000, SHIFTL(7, 24, 3) |
                            SHIFTL(MIN((((bitmap->width * bitmap->height) + 1) >> 1) - 1, 0x7FF), 12, 12) |
                            SHIFTL(CALC_DXT(bitmap->width, 1), 0, 12));
        GFX(0xE7000000, 0);
        SET_TILE(2, 1, ((bitmap->width * 1) + 7) >> 3, 0, 0, 0, 1, bitmap->maskt, 0, 2, bitmap->masks, 0);
        GFX(0xF2000000, SHIFTL((bitmap->width - 1) << 2, 12, 12) | SHIFTL((bitmap->height - 1) << 2, 0, 12));
        GFX(0xE7000000, 0);
        TEX_RECT((bitmap->x + x) << 2, (bitmap->y + y) << 2, (bitmap->x + x + bitmap->width) << 2,
                 (bitmap->y + y + bitmap->height) << 2, 0, 0, (bitmap->height - 1) << 5, 1 << 10, -1 << 10);
        bitmap++;
        goto loop;
    }
    GFX(0xBA001301, 0x80000);
    GFX(0xE7000000, 0);
    GFX(0xB8000000, 0);
}
