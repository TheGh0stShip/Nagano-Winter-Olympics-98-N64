typedef struct {
    char pad0[4];
    unsigned short flags;
    char pad6[6];
    short w;
    short h;
    char pad10[0x130 - 0x10];
    int bank;
    char pad134[4];
    int tex;
    int pal;
    unsigned short *dst;
} Tex;

extern unsigned short *func_80005E18(int, int);
extern short D_801365C0;
extern short D_801365C2;

void func_8001B03C(Tex *t) {
    unsigned short *src;
    unsigned int i;
    unsigned int j;
    unsigned int x;
    unsigned int y;
    int pad;
    int k;
    unsigned int o;
    unsigned int c;
    unsigned short w;
    int h;

    k = 0;
    if ((t->w % 16) * 4) {
        D_801365C0 = 0x20;
    } else {
        D_801365C0 = 0x40;
    }
    D_801365C2 = 0x20;
    if (t->flags & 1) {
        if (t->flags & 0x8000) {
            func_80005E18(t->bank, t->pal);
            src = func_80005E18(t->bank, t->tex);
            y = 0;
        loop:
            t->dst[y] = *src++;
            y++;
            if (y < 0x100) goto loop;
            src = func_80005E18(t->bank, t->pal);
            w = t->w / 2;
            for (y = 0; y < t->h; y += D_801365C2) {
                for (x = 0; x < w; x += h) {
                    h = D_801365C0 / 2;
                    for (j = 0; j < D_801365C2; j++) {
                        for (i = 0; i < h; i++, k++, h = D_801365C0 / 2) {
                            if (h) {}
                            if (h) {}
                            if (x + i >= w) {
                                t->dst[k + 0x100] = 0;
                            } else if (y + j >= t->h) {
                                t->dst[k + 0x100] = 0;
                            } else {
                                t->dst[k + 0x100] = (&src[(int)(w * y + x)])[(int)(w * j + i)];
                            }
                        }
                    }
                }
            }
        } else {
            src = func_80005E18(t->bank, t->tex);
            for (y = 0; y < t->h; y += D_801365C2) {
                for (x = 0; x < t->w; x += h) {
                    h = D_801365C0;
                    o = t->w * y + x;
                    for (j = 0; j < D_801365C2; j++) {
                        for (i = 0; i < h; h = D_801365C0, i++, k++) {
                            if (h) {}
                            if (h) {}
                            if (x + i >= t->w) {
                                t->dst[k] = 0x7C0;
                            } else if (y + j >= t->h) {
                                t->dst[k] = 0xF100;
                            } else {
                                h = t->w * j + i;
                                t->dst[k] = (&src[(int)o])[h];
                            }
                        }
                    }
                }
            }
        }
        t->flags &= ~1;
    }
}
