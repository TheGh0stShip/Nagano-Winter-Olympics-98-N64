typedef struct Local {
    unsigned char a[24][9];
    unsigned char b[24];
    unsigned char c[24];
    float f[24];
} Local;

typedef struct Table {
    unsigned char a[16][9];
    unsigned char b[16];
    unsigned char pad[0xE0];
    signed char c[16];
    float f[16];
} Table;

extern void func_8002810C(void);
extern void func_800281C0(unsigned char, unsigned char);
extern void func_800285D4(void);
extern void func_80028770(unsigned char, unsigned char, Local *);
extern void func_80028864(unsigned short, Local *);
extern void func_80028C94(void);
extern void func_80028D7C(Local *);
extern int func_800296C0(float, float);
extern float func_80029728(void);
extern void func_8002A9B0(void);
extern void func_8002AB2C(void);
extern void func_8002B0FC(int, int);
extern void func_8002B624(void);
extern void func_800366E0(long long);
extern signed char D_80071A50[];
extern unsigned char *D_80126BF0;
extern Table D_80137150;
extern unsigned char D_801374B2;
extern unsigned char D_801376D0[];
extern unsigned char D_801376D8[][9];

void func_80027CEC(void) {
    Local l;
    float a;
    float b;
    unsigned short i;
    unsigned short j;

    if (D_80126BF0[0x977EF] == 0 && D_80126BF0[0x977F2] == 0) {
        if (D_80126BF0[0x977F4] != 0 && D_80126BF0[0x977EC] == 7) {
            func_800366E0(0x93D0);
        }
        func_8002B624();
        func_80028C94();
        func_80028D7C(&l);
        if (D_801374B2 == 0xB && D_80126BF0[0x977EC] != 6) {
            func_800285D4();
            return;
        }
        for (i = 0; i < 24; i++) {
            func_80028864(i, &l);
        }
        for (i = 0; i < 23; i++) {
            for (j = 0; j < 23; j++) {
                a = l.f[j] * D_80071A50[D_801374B2];
                b = l.f[j + 1] * D_80071A50[D_801374B2];
                if (b <= a) {
                    func_80028770(j, j + 1, &l);
                }
            }
        }
        for (i = 0; i < 16; i++) {
            for (j = 0; j < 9; j++) {
                D_80137150.a[i][j] = l.a[i][j];
            }
            D_80137150.b[i] = l.b[i];
            D_80137150.f[i] = l.f[i];
        }
        for (i = 0; i < 15; i++) {
            if (func_800296C0(D_80137150.f[i], D_80137150.f[i + 1]) != 0) {
                D_80137150.f[i + 1] += func_80029728();
            }
        }
        func_8002B0FC(0, 15);
        for (i = 16 - D_80126BF0[0x977F0]; i < 16; i++) {
            for (j = 0; j < 9; j++) {
                D_80137150.a[i][j] = (D_801376D8 + (int)i)[D_80126BF0[0x977F0] - 16][j];
            }
            D_80137150.b[i] = ((unsigned char (*)[1])D_801376D0)[(int)i][D_80126BF0[0x977F0] - 16];
            D_80137150.f[i] = 0.0f;
            D_80137150.c[i] = (int)i - (15 - D_80126BF0[0x977F0]);
        }
        for (i = 0; i < 16; i++) {
            func_800281C0(i, (unsigned int)D_80137150.f[i]);
        }
        func_8002AB2C();
        func_8002810C();
        func_8002A9B0();
    }
}
