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
extern unsigned short D_8006350C;
extern unsigned char D_80063504;
extern unsigned char D_8008F3C8;
extern unsigned char D_8008F3D1;
extern short D_8008F3E0;
extern short D_8008F3E2;
extern void func_800138C4(void);
extern void func_800015C4(int, int, int);
extern void func_801954A0(void);
extern short func_801954F4(void);
extern void func_80001B7C(int arg);
extern void func_800127BC(void);
extern void func_80007E5C(void);
extern int func_8001CDA0(void);
extern void func_8000A8DC(int arg);

void func_80003530(void) {
    short result;

    switch (D_8006350C) {
    case 0:
        func_800138C4();
        D_8006350C = 1;
        D_8008F3E0 = 0;
        break;
    case 1:
        if (D_8008F3E0 == 0) {
            D_8008F3C8 = 1;
            func_800015C4(D_80063558[16].a, D_80063558[16].b, D_80063558[16].c - D_80063558[16].d);
            D_8008F3C8 = 0;
            D_8008F3E2 = D_80126BF0->timer;
            D_8008F3E0 = 1;
        } else if (D_80126BF0->timer - D_8008F3E2 >= 8) {
            func_801954A0();
            D_8006350C = 3;
        }
        break;
    case 3:
        result = func_801954F4();
        D_8008F3E0 = result;
        if (result < 0) {
            func_80001B7C(6);
            D_8006350C = 0;
        } else if (result != 0) {
            D_8006350C = 4;
        }
        break;
    case 4:
        D_80063504 = 1;
        func_800127BC();
        func_800138C4();
        func_80007E5C();
        D_8006350C = 5;
        break;
    case 5:
        if (func_8001CDA0()) {
            func_8000A8DC(1);
            D_8008F3D1 = 1;
            D_8006350C = 0;
            D_80063504 = 0;
            func_80001B7C(3);
        }
        break;
    default:
        D_8006350C = 0;
        break;
    }
}
