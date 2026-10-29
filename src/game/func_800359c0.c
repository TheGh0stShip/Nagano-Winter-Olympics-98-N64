typedef struct {
    unsigned int w0;
    unsigned int w1;
} GfxWords;
typedef union {
    GfxWords words;
    long long force_align;
} Gfx;
typedef struct Ent {
    char pad0[0xC];
    float x;
    float y;
    float z;
    char pad18[0x12C - 0x18];
    Gfx *dl;
    char pad130[0x138 - 0x130];
} Ent;
typedef struct Cam {
    char pad0[0x28];
    float rx;
    float ry;
    float rz;
    char pad34[0x78 - 0x34];
} Cam;
typedef struct Big {
    char pad0[0x7FB28];
    Cam cam[144];
    char pad83E28[0x83EF8 - 0x7FB28 - 144 * 0x78];
    Ent ent[1][1];
} Big;
typedef struct Wave {
    float x;
    float y;
    float z;
    float sx;
    float sy;
    float sz;
    float px[10];
    float py[10];
    float pz[10];
    float unk90;
    unsigned char unk94;
    char pad95[3];
} Wave;
typedef struct Sel {
    char pad0[8];
    short cam;
    short ent;
} Sel;
extern float func_80005550(float y, float x);
extern void func_800057B0(void *mtx, float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz);
extern void func_8002FD50(Ent *e, int r, int g, int b, int x, int y, int z);
extern void func_8002FD8C(Ent *e, int r, int g, int b);
extern short func_80036394(short slot);
extern float func_8004E9D0(float a);
extern float func_8005C4E0(float a);
extern float sqrtf(float);
#pragma intrinsic(sqrtf)
extern unsigned short D_80072AD0;
extern unsigned int D_80072A74[2];
extern unsigned int D_80072A80[2][10];
extern Big *D_80126BF0;
extern Gfx *D_80126BF4;
extern char *D_80126BFC;
extern Sel D_80137720;
extern short D_80137728[2];
extern short D_8013772A;
extern Wave D_80137730[];
extern short D_80137860;
extern float D_80137864;
extern Gfx D_0600B5D8[];
void func_800359C0(unsigned char slot) {
    short i;
    short rev;
    float step;
    float t;
    float ang;
    float r;
    float a;
    float b;
    float d;
    Wave *w;
    Cam *c;
    short k;
    float sc;
    float pad[17];
    float cx;
    w = &D_80137730[slot];
    step = (w->unk90 - 1.0f) / (float)(D_80137860 - 1);
    D_80126BF0->ent[D_80137720.ent][slot].x = w->x;
    D_80126BF0->ent[D_80137720.ent][slot].y = w->y;
    D_80126BF0->ent[D_80137720.ent][slot].z = w->z;
    D_80126BF0->ent[D_80137720.ent][slot].dl = D_80126BF4;
    c = &D_80126BF0->cam[D_80137720.cam];
    cx = func_8005C4E0(((float)((double)(c->rx) * 3.141592653589793 / 180.0)));
    a = func_8004E9D0(((float)((double)(c->ry) * 3.141592653589793 / 180.0))) * -cx;
    b = func_8004E9D0(((float)((double)(c->rx) * 3.141592653589793 / 180.0)));
    cx = func_8005C4E0(((float)((double)(c->rx) * 3.141592653589793 / 180.0)));
    d = func_8005C4E0(((float)((double)(c->ry) * 3.141592653589793 / 180.0))) * -cx;
    ang = (float)((double)(func_80005550(b, a) * 180.0f) / 3.141592653589793);
    r = sqrtf(a * a + b * b);
    a = func_8005C4E0(((float)((double)(c->rz + ang) * 3.141592653589793 / 180.0))) * r;
    t = func_8004E9D0(((float)((double)(c->rz + ang) * 3.141592653589793 / 180.0))) * r;
    func_8002FD50(&D_80126BF0->ent[D_80137720.ent][slot], 0xEF, 0xEF, 0xEF, (int)(-64.0f * a), (int)(-64.0f * t), (int)(-64.0f * d));
    func_8002FD8C(&D_80126BF0->ent[D_80137720.ent][slot], 0x9F, 0x9F, 0x9F);
    rev = func_80036394(slot);
    { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0x06000000); _g->words.w1 = (unsigned int)(D_0600B5D8); };
    for (i = 0; i < D_80137860; i++) {
        if (rev) {
            k = D_80137860 - i - 1;
        } else {
            k = i;
        }
        sc = ((float)k + 0.125f * (float)(D_80072AD0 % 8)) * step + 1.0f;
        func_800057B0(D_80126BFC,
                      ((D_80137730[slot].sx) * (D_80137730[slot].px)[k]) * ((float)k + 0.05f * (float)(D_80072AD0 % 20)) * D_80137864,
                      ((D_80137730[slot].sy) * (D_80137730[slot].py)[k]) * ((float)k + 0.05f * (float)(D_80072AD0 % 20)) * D_80137864,
                      ((D_80137730[slot].sz) * (D_80137730[slot].pz)[k]) * ((float)k + 0.05f * (float)(D_80072AD0 % 20)) * D_80137864,
                      (D_80126BF0->cam[D_80137720.cam].rx), (D_80126BF0->cam[D_80137720.cam].ry), (D_80126BF0->cam[D_80137720.cam].rz), sc, sc, sc);
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xE7000000); _g->words.w1 = (unsigned int)(0); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0x01040040); _g->words.w1 = (unsigned int)(D_80126BFC + 0x80000000); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xE7000000); _g->words.w1 = (unsigned int)(0); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xFD100000); _g->words.w1 = (unsigned int)(D_80072A80[w->unk94 & 1][(k * 9) / (D_80137860 - 1) % 10]); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xF5100000); _g->words.w1 = (unsigned int)(0x07094250); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xE6000000); _g->words.w1 = (unsigned int)(0); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xF3000000); _g->words.w1 = (unsigned int)(0x073FF100); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xE7000000); _g->words.w1 = (unsigned int)(0); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xF5101000); _g->words.w1 = (unsigned int)(0x00094250); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xF2000000); _g->words.w1 = (unsigned int)(0x0007C07C); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xFA000000); _g->words.w1 = (unsigned int)((((unsigned int)(0xEF - k * 4) & 0xFF) << 24) | (((unsigned int)(0xEF - k * 2) & 0xFF) << 16) | ((unsigned int)(0xEF & 0xFF) << 8) | ((unsigned int)(0x70 - k * (0x40 / D_80137860)) & 0xFF)); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0x06000000); _g->words.w1 = (unsigned int)(D_80072A74[w->unk94 & 1]); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xE7000000); _g->words.w1 = (unsigned int)(0); };
        { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xBD000000); _g->words.w1 = (unsigned int)(0); };
        D_80126BFC += 0x40;
    }
    { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xE7000000); _g->words.w1 = (unsigned int)(0); };
    { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xB9000002); _g->words.w1 = (unsigned int)(0); };
    { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xF9000000); _g->words.w1 = (unsigned int)(1); };
    { Gfx *_g = (Gfx *)(D_80126BF4++); _g->words.w0 = (0xB8000000); _g->words.w1 = (unsigned int)(0); };
}
