typedef struct {
    unsigned char pad0;
    unsigned char count;
    unsigned char a[16][9];
    unsigned char b[16];
    unsigned char c[16][7];
} Src800285D4;
typedef struct {
    unsigned char a[16][9];
    unsigned char b[16];
    unsigned char c[16][7];
    unsigned char d[16][7];
    unsigned char e[16];
    float f[16];
} Dst800285D4;
extern Src800285D4 D_801373A0;
extern Dst800285D4 D_80137150;
extern void func_8000EC50(Src800285D4 *);
extern void func_8002A5E8(unsigned char, unsigned char *);
extern void func_8002B0FC(int, int);

void func_800285D4(void) {
    int pad;
    unsigned char buf[6];
    unsigned short i;
    unsigned short j;

    func_8000EC50(&D_801373A0);
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 9; j++) D_80137150.a[i][j] = D_801373A0.a[i][j];
        D_80137150.b[i] = D_801373A0.b[i];
        for (j = 0; j < 6; j++) D_80137150.f[i] += D_801373A0.c[i][j];
        if (i < D_801373A0.count) D_80137150.e[i] = i + 1;
        func_8002A5E8(i, buf);
        for (j = 0; j < 6; j++) D_80137150.d[i][j] = buf[j];
        for (j = 0; j < 6; j++) D_80137150.c[i][j] = D_801373A0.c[i][j];
    }
    func_8002B0FC(0, 15);
}
