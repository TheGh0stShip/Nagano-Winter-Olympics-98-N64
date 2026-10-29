typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Object {
    unsigned char pad0[8];
    float kind;
    unsigned char padC[0x11C];
    int light;
    Gfx *list;
} Object;

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern unsigned char D_8006F640[][10];
extern Gfx D_06004400[];
extern unsigned char D_06000000[];
extern unsigned char D_060041A0[];
extern unsigned char D_06004360[];
extern unsigned int func_80005E18(int mode, void *texture);
extern void func_80017F0C(int arg, unsigned short row, unsigned short column);

#define _SHIFTL(v, s, w) ((unsigned int)(((unsigned int)(v) & ((0x01 << (w)) - 1)) << (s)))
#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }
#define TRI_W1(v0, v1, v2) (_SHIFTL((v0) * 2, 16, 8) | _SHIFTL((v1) * 2, 8, 8) | _SHIFTL((v2) * 2, 0, 8))
#define gSP2Triangles(pkt, v00, v01, v02, flag0, v10, v11, v12, flag1) \
{ \
    Gfx *_g = (Gfx *)(pkt); \
    _g->w0 = (_SHIFTL(0xB1, 24, 8) | TRI_W1(v00, v01, v02)); \
    _g->w1 = TRI_W1(v10, v11, v12); \
}

void func_800191D4(Object *obj, unsigned short mode, unsigned short color) {
    int reserved;
    unsigned char count = 7;
    unsigned char prev;
    int started = 0;
    int skipped = 0;
    unsigned short index;
    unsigned char *text;
    short i;
    unsigned char digit;
    unsigned int image;

    prev = 0xFF;
    if (mode) {
        count = 6;
    }
    index = obj->kind;
    if (index < 0 || index >= 20) {
        return;
    }
    text = D_8006F640[index];
    if (text == 0) {
        return;
    }
    obj->list = D_80126BF4;
    GFX(0xBC001806, *(unsigned int *)(D_80126BF0 + 0x7C930));
    GFX(0x06000000, (unsigned int)D_06004400);
    GFX(0xE7000000, 0);
    GFX(0xFD100000, (unsigned int)D_06000000);
    GFX(0xE8000000, 0);
    GFX(0xF5000100, 0x07000000);
    GFX(0xE6000000, 0);
    GFX(0xF0000000, 0x073FC000);
    GFX(0xE7000000, 0);
    image = func_80005E18(1, D_060041A0);
    GFX(0xE7000000, 0);
    GFX(0x040071BF, image);
    for (i = 0; i < count; i++, text++) {
        digit = *text - '0';
        if (digit >= 10) {
            digit = 0;
        }
        if (!started) {
            if ((i == 0 || i == 2) && digit == 0) {
                continue;
            }
            if (i == 1 && digit == 0) {
                skipped = 1;
                continue;
            }
        }
        started = 1;
        if (digit != prev) {
            func_80017F0C(1, color, digit);
        }
        gSP2Triangles(D_80126BF4++, i * 4 + 2, i * 4 + 1, i * 4, 0, i * 4 + 3, i * 4, i * 4 + 1, 0);
        prev = digit;
    }
    image = func_80005E18(1, D_06004360);
    GFX(0xE7000000, 0);
    GFX(0x0400207F, image);
    for (i = 0; i < 2; i++) {
        if (skipped && i == 0) {
            continue;
        }
        func_80017F0C(1, color, i + 10);
        gSP2Triangles(D_80126BF4++, i * 4 + 2, i * 4 + 1, i * 4, 0, i * 4 + 3, i * 4, i * 4 + 1, 0);
    }
    GFX(0xE7000000, 0);
    GFX(0xBC001806, ((unsigned int *)(D_80126BF0 + 0x7C92C))[obj->light]);
    GFX(0xB8000000, 0);
}
