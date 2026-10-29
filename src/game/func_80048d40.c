typedef struct {
    unsigned short m0;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
} Src;

typedef struct {
    char pad[0xC];
    short x;
    short y;
    signed char z;
} Dst;

extern unsigned short D_80179928;
extern Src *D_8017992C;
extern Dst D_80179688;
extern unsigned int D_801796F8;
extern void func_80049470(int);

void func_80048D40(void) {
    short a;
    short b;
    short c;
    short lim;
    Src *p;
    int t;
    int f1;
    int f2;
    int f4;
    unsigned int m0;
    Dst *d;
    int *q;

    a = D_80179928 >> 3;
    t = a >> 3;
    b = t;
    c = t;
    c >>= 3;
    if (1) {
        a &= 0x3FFF;
        b &= 0xFF;
        c &= 0x7F;
    }
    if (D_8017992C->m2) {
        lim = D_8017992C->m2 << 8;
        while (lim < a) a >>= 1;
    } else {
        a = 0;
    }
    if (D_8017992C->m3) {
        while (D_8017992C->m3 < b) b >>= 1;
    } else {
        b = 0;
    }
    if (D_8017992C->m4) {
        while (D_8017992C->m4 < c) c >>= 1;
    } else {
        c = 0;
    }
    if (D_80179928 & 1) a = -a;
    if (D_80179928 & 2) b = -b;
    if (D_80179928 & 4) c = -c;
    if (b) b += 0x100;
    D_801796F8 = D_8017992C->m0;
    D_80179688.x = a;
    D_80179688.y = b;
    D_80179688.z = c;
    if (D_801796F8 >= 0x100) func_80049470(1);
    D_8017992C = 0;
}
