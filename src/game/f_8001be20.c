typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Mtx {
    int m[4][4];
} Mtx;

typedef struct PackedRecord {
    signed short first;
    signed short second;
    signed short third;
    signed short zero;
    signed short fourth;
    signed short fifth;
    unsigned char sixth;
    unsigned char seventh;
    unsigned char eighth;
    unsigned char ninth;
} PackedRecord;

#define SHIFTL(v, s, w) ((unsigned int)(((unsigned int)(v) & ((0x01 << (w)) - 1)) << (s)))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define TXL2WORDS(txls, b_txl) MAX(1, ((txls) * (b_txl) / 8))
#define CALC_DXT(width, b_txl) (((1 << 11) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))
#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }

extern Gfx *D_80126BF4;
extern Mtx *D_80126BFC;
extern short D_801365C0;
extern short D_801365C2;
extern PackedRecord D_801365C8[4];
extern void func_8005DD18(Mtx *m, float x, float y, float z);
extern void func_8001BDB8(PackedRecord *record, signed short first, signed short second, signed short third,
                          signed short fourth, signed short fifth, unsigned char sixth, unsigned char seventh,
                          unsigned char eighth, unsigned char ninth);

void func_8001BE20(unsigned short *texels, unsigned short flags, short x, short y) {
    if (flags & 0x8000) {
        GFX(0xFD500000, (unsigned int)texels);
        GFX(0xF5500000, 0x07094260);
        GFX(0xE6000000, 0);
        GFX(0xF3000000, SHIFTL(7, 24, 3) | SHIFTL(MIN((((D_801365C0 * D_801365C2) + 1) >> 1) - 1, 0x7FF), 12, 12) |
                            SHIFTL(CALC_DXT(D_801365C0, 1), 0, 12));
        GFX(0xE7000000, 0);
        GFX(0xF5480000 | SHIFTL(((D_801365C0 * 1) + 7) >> 3, 9, 9), 0x00094260);
        GFX(0xF2000000, SHIFTL((D_801365C0 - 1) << 2, 12, 12) | SHIFTL((D_801365C2 - 1) << 2, 0, 12));
    } else {
        GFX(0xFD100000, (unsigned int)texels);
        GFX(0xF5100000, 0x07094260);
        GFX(0xE6000000, 0);
        GFX(0xF3000000, SHIFTL(7, 24, 3) | SHIFTL(MIN((((D_801365C0 * D_801365C2) + 0) >> 0) - 1, 0x7FF), 12, 12) |
                            SHIFTL(CALC_DXT(D_801365C0, 2), 0, 12));
        GFX(0xE7000000, 0);
        GFX(0xF5100000 | SHIFTL(((D_801365C0 * 2) + 7) >> 3, 9, 9), 0x00094260);
        GFX(0xF2000000, SHIFTL((D_801365C0 - 1) << 2, 12, 12) | SHIFTL((D_801365C2 - 1) << 2, 0, 12));
    }
    func_8005DD18(D_80126BFC, (short)(x - 160), (short)(y - 120), 0.0f);
    func_8001BDB8(&D_801365C8[0], 0, 32, 0, 32, 0x800, 0, 0, 0x7F, 0xFF);
    func_8001BDB8(&D_801365C8[1], 64, 0, 0, 0x1020, 0, 0, 0, 0x7F, 0xFF);
    func_8001BDB8(&D_801365C8[2], 0, 0, 0, 32, 0, 0, 0, 0x7F, 0xFF);
    func_8001BDB8(&D_801365C8[3], 64, 32, 0, 0x1020, 0x800, 0, 0, 0x7F, 0xFF);
    GFX(0xE7000000, 0);
    GFX(0x01040040, (unsigned int)D_80126BFC + 0x80000000);
    D_80126BFC++;
    GFX(0x0400103F, (unsigned int)D_801365C8);
    GFX(0xB1040200, 0x00060002);
    GFX(0xBD000000, 0);
}
