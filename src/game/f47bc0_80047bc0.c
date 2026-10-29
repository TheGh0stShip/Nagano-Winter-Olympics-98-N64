typedef struct Info {
    int first;
    short count;
} Info;

typedef struct Ctx {
    int handle;
    short size;
    short pad6;
    int f8;
    int padC;
    int f10;
    int padChunk[1];
    int f18;
    int f1C;
    void *f20;
    int f24;
    void *f28;
    int pad2C;
    void *f30;
    int f34;
    unsigned char pad38[0x10];
    int f48;
    int f4C;
    int f50;
    int f54;
    void *f58;
    void *f5C;
    unsigned char pad60[0x10];
    unsigned char buf70[1];
} Ctx;

extern int D_8013CF04;
extern unsigned int D_8013CF00;
extern unsigned int D_80073688;
extern int D_801386C0[];
extern int D_8008F3C4;
extern unsigned char D_801389A0[];
extern unsigned char D_8005FFC0[];
extern unsigned char D_80060090[];
extern unsigned char D_800614C0[];
extern unsigned char D_80081B20[];

extern void func_80047F60(void);
extern int func_800512C0(int a);
extern void func_8005FE60(int a, int b);
extern int func_8005DB30(void);
extern int func_80055508(int a, int *b, int c, int d);
extern void func_8004E2A0(int a, void *b, int c);

int func_80047BC0(Ctx *ctx, Info *info) {
    int handle;
    int pad1[1];
    int found;
    int pad[1];
    int result;

    func_80047F60();
    handle = func_800512C0(ctx->handle);
    if (info != 0) {
        func_8005FE60(info->first, info->count * 4);
    }
    ctx->size = (D_8013CF04 - ((unsigned int)func_8005DB30() >> 2) + 0xB0) & 0xFFF0;
    if (ctx->size < D_8013CF00) {
        ctx->size = D_8013CF00;
    }
    result = func_80055508(D_801386C0[D_80073688], &found, handle, ctx->size);
    if (found == 0) {
        return 0;
    }
    ctx->f8 = 0;
    ctx->f58 = D_801389A0;
    ctx->f5C = ctx->buf70;
    ctx->f10 = 2;
    ctx->f48 = D_801386C0[D_80073688];
    ctx->f4C = ((result - D_801386C0[D_80073688]) >> 3) << 3;
    ctx->f18 = 2;
    ctx->f20 = D_8005FFC0;
    ctx->f24 = D_80060090 - D_8005FFC0;
    ctx->f1C = 0;
    ctx->f28 = D_800614C0;
    ctx->f30 = D_80081B20;
    ctx->f34 = 0x800;
    ctx->f50 = 0;
    ctx->f54 = 0;
    func_8004E2A0(D_8008F3C4, &ctx->f8, 1);
    D_80073688 ^= 1;
    return 1;
}
