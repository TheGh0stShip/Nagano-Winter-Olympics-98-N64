typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

extern Gfx *D_80126BF4;
extern void *D_8006EFD0[][19];
extern unsigned int func_80005E18(void *arg, void *texture);

#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }

void func_80017F0C(void *arg, unsigned short row, unsigned short column) {
    unsigned int image;

    image = func_80005E18(arg, D_8006EFD0[row][column]);
    GFX(0xE7000000, 0);
    GFX(0xFD500000, image);
    GFX(0xF5500000, 0x07090240);
    GFX(0xE6000000, 0);
    GFX(0xF3000000, 0x0705F400);
    GFX(0xE7000000, 0);
    GFX(0xF5480400, 0x00090240);
    GFX(0xF2000000, 0x0003C02C);
    GFX(0xE7000000, 0);
}
