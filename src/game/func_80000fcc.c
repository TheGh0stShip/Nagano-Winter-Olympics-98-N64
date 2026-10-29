typedef struct { unsigned int w0, w1; } Gfx;
typedef struct { Gfx g[0x29840 / 8]; } Buf;
typedef struct {
    Buf buf[3];
    short idx;
} GfxPool;
typedef struct {
    int pad0[2];
    int type;
    int pad1[4];
    int size1C;
    int pad2[6];
    void *p38;
    void *p3C;
    void *p40;
    int len44;
    int pad3[4];
} Task;
extern GfxPool *D_80126BF0;
extern Gfx *D_80126BF4;
extern Task D_800633D8[];
extern char D_8005FFC0[];
extern char D_80060090[];
extern char D_80127C10[];
extern char D_8008C650[];
extern int D_8008F3C0;
extern void func_80051340(void *, int);
extern void func_80004530(void *, int, Task *, void *);

void func_80000FCC(void) {
    Task *t;

    { Gfx *_g = (Gfx *)(D_80126BF4++); _g->w0 = 0xE9000000; _g->w1 = 0; }
    { Gfx *_g = (Gfx *)(D_80126BF4++); _g->w0 = 0xB8000000; _g->w1 = 0; }
    func_80051340(D_80126BF0->buf[D_80126BF0->idx].g, sizeof(D_80126BF0->buf[0]));
    t = &D_800633D8[D_80126BF0->idx];
    t->p40 = &D_80126BF0->buf[D_80126BF0->idx];
    t->len44 = ((int)((char *)D_80126BF4 - (char *)&D_80126BF0->buf[D_80126BF0->idx]) >> 3) * 8;
    t->size1C = D_80060090 - D_8005FFC0;
    t->p38 = D_80127C10;
    t->p3C = (void *)((int)D_80127C10 + 0x2FD0);
    t->type = 0x63;
    func_80004530(D_8008C650, D_8008F3C0, t, D_80127C10);
}
