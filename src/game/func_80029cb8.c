typedef struct Game {
    unsigned char pad0[0x977EC];
    unsigned char mode;
    unsigned char pad977ED[2];
    unsigned char a;
    unsigned char b;
    unsigned char pad977F1;
    unsigned char c;
} Game;

typedef struct Tbl {
    unsigned char names[16][9];
    unsigned char kind[16];
    unsigned char data[16][7];
    unsigned char pad110[0x180 - 0x110];
    unsigned char active[16];
    float val[16];
} Tbl;

typedef struct Res {
    unsigned char mode;
    unsigned char count;
    unsigned char names[16][9];
    unsigned char kind[16];
    unsigned char data[16][7];
} Res;

extern Game *D_80126BF0;
extern Tbl D_80137150;
extern Res D_801373A0;
extern unsigned char D_801374B2;
extern signed char D_801374C9;
extern unsigned char D_801374C0[];
extern signed char D_80071A50[];
extern signed char D_80071A5C[];
extern void func_80012788(void);
extern void func_8002B624(void);
extern float func_8002932C(float);
extern float func_80029088(float);
extern float func_800290F4(float);
extern float func_80029C18(float *);
extern float func_80028F4C(float);
extern void func_8002A300(float *);
extern void func_800281C0(unsigned char, unsigned char);
extern void func_80029870(void);
extern void func_800297A8(void);
extern void func_8002984C(void);
extern void func_80029A74(void);
extern void func_8000EDB8(Res *);
extern void func_8002A9B0(void);
extern void func_8002A1BC(void);
extern void func_8002A0F8(float);
extern void func_8002A4E4(void);
extern void func_8002A37C(void);

float func_80029CB8(float t) {
    char pad2[0xC];
    float amt;
    float res;
    char pad[0x24];
    unsigned short i;
    unsigned short k;
    unsigned short n;
    unsigned char place;
    unsigned char pm;

    D_801374C9 = 0;
    func_80012788();
    func_8002B624();
    t = func_8002932C(t);
    if (t == -1.0f) {
        D_801374C0[D_80126BF0->c * 4 + D_80126BF0->a] = 1;
    }
    res = func_80029088(t);
    amt = res;
    amt = func_800290F4(res);
    amt = func_80029C18(&amt);
    if (D_801374B2 == 11) {
        amt = func_80028F4C(t);
        res = t;
    }
    func_8002A300(&amt);
    for (i = 0; i < 16; i++) {
        if (D_80126BF0->a + 1 == D_80137150.active[i]) {
            D_80137150.val[i] += amt;
            func_800281C0(i, (unsigned int)amt);
        }
    }
    if (D_801374B2 != 11) {
        func_80029870();
    }
    if (D_80071A50[D_801374B2] == 1) {
        func_800297A8();
    } else {
        func_8002984C();
    }
    if (D_801374B2 != 11) {
        func_80029A74();
    }
    n = 0;
    if (D_801374B2 == 11) {
        for (i = 0; i < 16; i++) {
            if (D_80137150.active[i] != 0) {
                for (k = 0; k < 9; k++) {
                    D_801373A0.names[D_80137150.active[i] - 1][k] = D_80137150.names[i][k];
                }
                D_801373A0.kind[D_80137150.active[i] - 1] = D_80137150.kind[i];
                for (k = 0; k < 7; k++) {
                    pm = D_80137150.active[i] - 1;
                    D_801373A0.data[pm][k] = D_80137150.data[i][k];
                }
                n++;
            }
        }
        D_801373A0.count = n;
        for (i = 0; i < 16; i++) {
            if (D_80137150.active[i] == 0) {
                for (k = 0; k < 9; k++) {
                    D_801373A0.names[n][k] = D_80137150.names[i][k];
                }
                D_801373A0.kind[n] = D_80137150.kind[i];
                for (k = 0; k < 7; k++) {
                    D_801373A0.data[n][k] = D_80137150.data[i][k];
                }
                n++;
            }
        }
        D_801373A0.mode = D_80071A5C[D_80126BF0->mode] + 1;
        func_8000EDB8(&D_801373A0);
    }
    func_8002A9B0();
    func_8002A1BC();
    func_8002A0F8(res);
    if (D_801374B2 == 11) {
        func_8002A4E4();
    } else {
        func_8002A37C();
    }
    return res;
}
