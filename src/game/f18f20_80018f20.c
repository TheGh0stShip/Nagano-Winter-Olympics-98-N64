typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Mtx {
    int m[4][4];
} Mtx;

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern Mtx *D_80126BFC;
extern Gfx D_060060B0[];
extern Gfx D_06006128[];
extern Gfx D_060061D8[];
extern Gfx D_06006288[];
extern Gfx D_06006338[];
extern void func_8005DD18(Mtx *m, float x, float y, float z);

#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }

void func_80018F20(unsigned char kind, unsigned short alpha, float x, float y, float z) {
    GFX(0xE7000000, 0);
    GFX(0xBC001806, *(unsigned int *)(D_80126BF0 + 0x7C930));
    func_8005DD18(D_80126BFC, x, y, z);
    GFX(0x01040040, (unsigned int)D_80126BFC + 0x80000000);
    D_80126BFC++;
    GFX(0x06000000, (unsigned int)D_060060B0);
    GFX(0xE7000000, 0);
    GFX(0xFA000000, (0x20 << 24) | (0x20 << 16) | (0xFF << 8) | (alpha & 0xFF));
    GFX(0xE7000000, 0);
    switch (kind) {
        case 0:
            GFX(0x06000000, (unsigned int)D_06006128);
            break;
        case 1:
            GFX(0x06000000, (unsigned int)D_060061D8);
            break;
        case 2:
            GFX(0x06000000, (unsigned int)D_06006338);
            break;
        case 3:
            GFX(0x06000000, (unsigned int)D_06006288);
            break;
    }
    GFX(0xBD000000, 0);
    GFX(0xE7000000, 0);
}
