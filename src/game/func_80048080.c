typedef struct ParamsA {
    int w0;
    int w1;
    int w2;
    int pad;
    int w4;
    void *ptr;
    int w6;
    unsigned char kind;
    void *ptr2;
} ParamsA;

typedef struct ParamsB {
    int rate;
    int w1;
    int w2;
} ParamsB;

extern unsigned char D_8013D648[];
extern unsigned char D_8013D668[];
extern unsigned char D_8013D630[];
extern unsigned char *D_8013D658[4];
extern unsigned char D_80179980[];
extern unsigned int D_80073690[];
extern unsigned int D_800736A0[];
extern unsigned int D_800736B0[];
extern unsigned char D_800736D0[];
extern void func_8005A3F0(void *, void *, int);
extern void func_800015C4(unsigned int, unsigned char *, unsigned int);
extern void func_80050F44(unsigned char *, unsigned int);
extern void func_80047770(ParamsA *, int, ParamsB *);
extern void func_80048274(void *);

void func_80048080(void) {
    ParamsA a;
    ParamsB b;
    unsigned int i;
    int k;
    int offset;
    unsigned int size;
    unsigned int src;

    i = 0; do { if (0) {} i += 4; } while (i != 0x100000);
    func_8005A3F0(D_8013D648, D_8013D668, 0x3C000);
    offset = 0;
    for (k = 0; k < 4; k++) {
        size = D_800736A0[k] - D_80073690[k];
        src = D_80073690[k];
        D_8013D658[k] = D_80179980 + offset;
        for (i = 0; i < size; i++) { (D_80179980 + offset)[i] = 0; }
        i = 0;
        func_800015C4(src, D_8013D658[k], size);
        offset += size;
    }
    for (k = 0; k < 4; k++) {
        func_80050F44(D_8013D658[k], D_800736B0[k]);
    }
    a.w0 = 16;
    a.w1 = 16;
    a.w2 = 0xA0;
    a.w4 = 0;
    a.w6 = 0;
    a.ptr = D_8013D648;
    a.kind = 6;
    a.ptr2 = D_800736D0;
    b.rate = 0xAC44;
    b.w1 = 1;
    b.w2 = 0x1000;
    func_80047770(&a, 12, &b);
    func_80048274(D_8013D630);
    i = 0;
loop2:
    i += 4;
    if (i != 0x100000) goto loop2;
}
