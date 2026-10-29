typedef struct Rec {
    int a;
    int b;
    int c;
    int d;
} Rec;

typedef struct Runtime {
    unsigned char pad0[0x7C8D8];
    unsigned short timer;
} Runtime;

extern Rec D_80063558[];
extern Runtime *D_80126BF0;
extern short D_8006350C;
extern unsigned char D_8008F3C8;
extern unsigned char D_8008F3DE;
extern unsigned char D_8008F3DF;
extern void func_800138C4(void);
extern void func_800015C4(int, int, int);
extern void func_801954A0(void);
extern short func_801954EC(void);
extern void func_80001B7C(int arg);

void func_800033E0(void) {
    short result;

    switch (D_8006350C) {
    case 0:
        func_800138C4();
        D_8008F3DE = 0;
        D_8006350C = 3;
        break;
    case 3:
        if (D_8008F3DE == 0) {
            D_8008F3C8 = 1;
            func_800015C4(D_80063558[17].a, D_80063558[17].b, D_80063558[17].c - D_80063558[17].d);
            D_8008F3C8 = 0;
            D_8008F3DF = D_80126BF0->timer;
            D_8008F3DE = 1;
        } else if (D_8008F3DE == 1) {
            if (D_80126BF0->timer - D_8008F3DF >= 8) {
                func_801954A0();
                D_8008F3DE = 2;
            }
        } else {
            result = func_801954EC();
            if (result < 0) {
                func_80001B7C(6);
            }
            if (result > 0) {
                func_80001B7C(6);
            }
        }
        break;
    default:
        D_8006350C = 0;
        break;
    }
}
