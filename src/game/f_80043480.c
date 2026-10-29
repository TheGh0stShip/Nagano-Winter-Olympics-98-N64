typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Slot {
    Gfx *gfx;
    unsigned char pad4[0x134];
} Slot;

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

void func_80043480(unsigned char index, unsigned char textured, unsigned int arg, short x, short y, short w, short h) {
    ((Slot *)(D_80126BF0 + 0x84024))[index].gfx = D_80126BF4;
    GFX(0x06000000, arg);
    GFX(0xBA001301, 0);
    if (textured) {
        GFX(0xBA001402, 0);
        TEX_RECT(x << 2, y << 2, ((x + w) * 2 + 1) << 1, ((y + h) * 2 + 1) << 1, 0, 0, 0, 1 << 10, 1 << 10);
    } else {
        GFX(0xBA001402, 0x200000);
        {
            Gfx *_g = D_80126BF4++;
            _g->w0 = 0xE4000000 | SHIFTL((x + w - 1) << 2, 12, 12) | SHIFTL((y + h - 1) << 2, 0, 12);
            _g->w1 = SHIFTL(x * 4, 12, 12) | SHIFTL(y * 4, 0, 12);
        }
        GFX(0xB4000000, 0);
        GFX(0xB3000000, 0x10000400);
    }
    GFX(0xBA001301, 0x80000);
    GFX(0xBA001402, 0);
    GFX(0xB8000000, 0);
}
