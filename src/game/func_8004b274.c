typedef struct Car {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x28 - 7];
    int unk28;
    unsigned char pad2C[0x36 - 0x2C];
    short unk36;
    unsigned short unk38;
    unsigned char pad3A[0xA2 - 0x3A];
    short unkA2;
    unsigned char padA4[0xA8 - 0xA4];
    float unkA8;
    unsigned char padAC[0xBE - 0xAC];
    short unkBE;
} Car;

typedef struct Snd {
    unsigned char pad[0x1C];
} Snd;

extern Car *D_80179924;
extern float D_800738B0[];
extern int D_8007C910;
extern unsigned char D_8017966C;
extern Snd D_80179760[];
extern void func_80053F90(int, Snd *, float);

void func_8004B274(void) {
    int v;
    unsigned int frac;
    float *tbl;
    float f;
    float base;
    float diff;
    float d = 256.0f;
    Car *c;

    D_80179924->flags &= 0xFD;

    v = D_80179924->unk28 + D_80179924->unk38 + D_80179924->unk36 + D_80179924->unkA2; v += D_80179924->unkBE;
    if (v < 0) {
        v = 0;
    } else if (v > 0x4800) {
        v = 0x4800;
    }
    frac = v & 0xFF;
    v >>= 8;
    tbl = &D_800738B0[v];
    base = tbl[0];
    f = tbl[1] - base;
    f = frac * f / d; f += base;
    if (f != D_80179924->unkA8) {
        D_80179924->unkA8 = f;
        func_80053F90(D_8007C910, &D_80179760[D_8017966C], f);
    }
}
