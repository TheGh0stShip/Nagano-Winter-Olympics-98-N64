typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Object {
    unsigned char pad0[8];
    float value;
    unsigned char padC[0x11C];
    int light;
    Gfx *list;
} Object;

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern Gfx D_06004400[];
extern unsigned char D_06000000[];
extern unsigned char D_06004478[];
extern unsigned char D_060044B8[];
extern unsigned int func_80005E18(int mode, void *texture);
extern void func_80017F0C(int arg, unsigned short row, unsigned short column);

#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }

void func_80019CCC(Object *obj, unsigned short color, unsigned short decimals, unsigned short mode) {
    unsigned int mtx;
    unsigned char digit;
    unsigned char prev;
    unsigned char ints[6];
    unsigned char frac[4];
    int iv;
    int fv;
    unsigned int vtx;
    float value;
    float add;
    float scale;
    unsigned short i;
    unsigned short n;
    unsigned short cnt;
    unsigned char *p;

    obj->list = D_80126BF4;
    GFX(0x06000000, (unsigned int)D_06004400);
    GFX(0xFD100000, (unsigned int)D_06000000);
    GFX(0xE8000000, 0);
    GFX(0xF5000100, 0x07000000);
    GFX(0xE6000000, 0);
    GFX(0xF0000000, 0x073FC000);
    GFX(0xE7000000, 0);
    cnt = 6;
    scale = 0.0f;
    vtx = func_80005E18(1, D_06004478);
    mtx = func_80005E18(1, D_060044B8);
    value = obj->value;
    iv = value;
    switch (decimals) {
        case 1:
            add = 0.02f;
            break;
        case 2:
            add = 0.002f;
            break;
        case 3:
            add = 0.0002f;
            break;
        default:
            add = 0.0f;
            break;
    }
    value += add;
    for (i = 0; i < decimals; i++) {
        scale *= 10.0f;
        value *= 10.0f;
    }
    fv = value - scale;
    for (i = 0, p = ints; i < cnt; i++, p++) {
        *p = iv % 10;
        iv = (iv - *p) / 10;
    }
    for (i = 0, p = frac; i < decimals; i++, p++) {
        *p = fv % 10;
        fv = (fv - *p) / 10;
    }
    p = frac;
    if ((unsigned int)mode != 0) switch (mode) {
        case 1:
            GFX(0xE7000000, 0);
            GFX(0x01000040, mtx);
            GFX(0x0400103F, vtx);
            func_80017F0C(1, color, 0xD);
            GFX(0xB1040200, 0x00060002);
            break;
        case 2:
            GFX(0xE7000000, 0);
            GFX(0x01000040, mtx);
            GFX(0x0400103F, vtx);
            func_80017F0C(1, color, 0x10);
            GFX(0xB1040200, 0x00060002);
            break;
        case 3:
            GFX(0xE7000000, 0);
            GFX(0x01000040, mtx);
            GFX(0x0400103F, vtx);
            func_80017F0C(1, color, 0x11);
            GFX(0xB1040200, 0x00060002);
            break;
    }
    prev = 0xFF;
    for (i = 0; i < decimals; i++, p++) {
        digit = *p;
        if (digit >= 10) {
            digit = 0;
        }
        GFX(0xE7000000, 0);
        GFX(0x01000040, mtx);
        GFX(0x0400103F, vtx);
        if (digit != prev) {
            func_80017F0C(1, color, digit);
        }
        GFX(0xB1040200, 0x00060002);
        prev = digit;
    }
    prev = 0xFF;
    if (mtx) {}
    if (decimals != 0) {
        GFX(0xE7000000, 0);
        GFX(0x01000040, mtx);
        GFX(0x0400103F, vtx);
        func_80017F0C(1, color, 0xB);
        GFX(0xB1040200, 0x00060002);
    }
    n = 6;
    p = &ints[5];
    i = 5;
    do {
        i--;
        if (*p) {
            break;
        }
        p--;
        n--;
    } while (i > 0);
    p = ints;
    for (i = 0; i < n; i++, p++) {
        digit = *p;
        if (digit >= 10) {
            digit = 0;
        }
        GFX(0xE7000000, 0);
        GFX(0x01000040, mtx);
        GFX(0x0400103F, vtx);
        if (digit != prev) {
            func_80017F0C(1, color, digit);
        }
        GFX(0xB1040200, 0x00060002);
        prev = digit;
    }
    if ((unsigned int)mode != 0) {
        if ((unsigned int)mode == 4) {
            GFX(0xE7000000, 0);
            GFX(0x01000040, mtx);
            GFX(0x0400103F, vtx);
            func_80017F0C(1, color, 0x12);
            GFX(0xB1040200, 0x00060002);
        }
    }
    GFX(0xE7000000, 0);
    GFX(0xBC001806, ((unsigned int *)(D_80126BF0 + 0x7C92C))[obj->light]);
    GFX(0xB8000000, 0);
}
