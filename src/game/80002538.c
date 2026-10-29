typedef struct InitBlock {
    int words[30];
} InitBlock;

typedef struct Rec {
    int a;
    int b;
    int c;
    int d;
} Rec;

typedef struct Runtime {
    unsigned char pad0[0x7C8D8];
    unsigned short timer;
    unsigned char pad7C8DA[0x36FE];
    InitBlock init;
} Runtime;

extern InitBlock D_800690E0;
extern Rec D_80063558[];
extern Runtime *D_80126BF0;
extern unsigned short D_8006350C;
extern unsigned char D_8008F3C8;
extern unsigned char D_8008F3D0;
extern void func_800138C4(void);
extern void func_8000FAE0(void);
extern void func_800015C4(int, int, int);
extern void func_801954A0(void);
extern int func_80198F30(void);
extern int func_8000FB24(void);
extern void func_80001B7C(int arg);

void func_80002538(void) {
    static short D_8008F3D6;
    static short D_8008F3D8;

    D_80126BF0->init = D_800690E0;
    switch (D_8006350C) {
    case 0:
        func_800138C4();
        func_8000FAE0();
        if (D_8008F3D0 != 0) {
            D_8006350C = 10;
        } else {
            D_8006350C = 1;
            D_8008F3D6 = 0;
        }
        break;
    case 1:
        if (D_8008F3D6 == 0) {
            D_8008F3C8 = 1;
            func_800015C4(D_80063558[17].a, D_80063558[17].b, D_80063558[17].c - D_80063558[17].d);
            D_8008F3C8 = 0;
            D_8008F3D8 = D_80126BF0->timer;
            D_8008F3D6 = 1;
        } else if (D_8008F3D6 == 1) {
            if (D_80126BF0->timer - D_8008F3D8 >= 8) {
                func_801954A0();
                D_8008F3D6 = 2;
            }
        } else if (func_80198F30() > 0) {
            D_8006350C = 10;
            D_8008F3D0 = 1;
        }
        break;
    case 10:
        D_8006350C = 11;
        break;
    case 11:
        D_8006350C = 3;
        break;
    case 3:
        D_8008F3D6 = func_8000FB24();
        if (D_8008F3D6 < 0) {
            func_80001B7C(4);
        }
        if (D_8008F3D6 > 0) {
            func_80001B7C(D_8008F3D6);
        }
        break;
    default:
        D_8006350C = 0;
        break;
    }
}
