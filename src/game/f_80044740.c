typedef struct Rec3140 {
    float x;
    float y;
    float z;
    float f0C;
    float f10;
    float f14;
    int pad18;
    int val1C;
    int val20;
    int w24;
} Rec3140;

typedef struct Obj {
    char pad[0x10];
    float f10;
    char pad2[0x10];
    float f24;
    float f28;
    float f2C;
} Obj;

extern Rec3140 D_80073140;
extern char D_060086D8[];
extern int D_8007315C;
extern int D_80073160;
extern unsigned char *D_80126BF0;
extern char D_80063958[];
extern char D_80063990[];
extern void func_80006D84(int, Rec3140 *);

void func_80044740(float *pos, int idx, unsigned char *src, float dx, float dy, void *kind) {
    Obj *o;
    unsigned char n;
    float f;
    int pad;

    D_80073140.f10 = 1.0f;
    f = D_80073140.f10;
    D_80073140.f14 = f;
    D_80073140.f0C = f;
    D_80073140.w24 = (int)kind;
    D_80073140.x = pos[0] + dx;
    D_80073140.y = pos[1] + dy - 2.0f;
    if (kind == (void *)D_060086D8) {
        D_8007315C = 20;
        D_80073160 = (int)D_80063990;
    } else {
        D_8007315C = 7;
        D_80073160 = (int)D_80063958;
    }
    ((unsigned char *)pos)[(unsigned char)idx + 0x19] = src[0x24];
    n = src[0x24];
    o = (Obj *)(D_80126BF0 + 0x8B2C0 + n * 0x148);
    src[0x24] = n + 1;
    func_80006D84(n, &D_80073140);
    if (o->f10 >= 0.0f) {
        f = (float)(int)o->f10;
        o->f10 = f - f / 4454.0f;
    }
    o->f2C = 1.0f;
    o->f28 = 1.0f;
    o->f24 = 1.0f;
}
