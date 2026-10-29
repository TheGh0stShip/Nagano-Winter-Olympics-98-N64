typedef struct Rec {
    int a;
    int b;
    int c;
    int d;
} Rec;

typedef struct Runtime {
    unsigned char pad0[0x7C8D8];
    unsigned short timer;
    unsigned char pad7C8DA[0x1AF12];
    unsigned char stage;
    unsigned char pad977ED[0x7];
    unsigned char loaded;
} Runtime;

extern Rec D_80063558[];
extern Runtime *D_80126BF0;
extern unsigned short D_8006350C;
extern unsigned short D_80063514;
extern unsigned char D_8006C3D0;
extern char D_801376D0;
extern int func_80043C30(void);
extern void func_800015C4(int, int, int);
extern void func_800118D0(void);
extern void func_80043C24(int arg);
extern int func_80030F70(void);
extern void func_8002C8E0(void);
extern void func_8002D508(void);
extern void func_80035854(void);
extern void func_8000AAC0(void);
extern void func_801954A0(void);
extern void func_801954E0(void);
extern int func_80005C48(void);
extern void func_80030E54(void);
extern void func_800485AC(int arg);
extern void func_80001B7C(int arg);

void func_80002188(void) {
    static unsigned char D_80063518 = 0;
    static unsigned short D_8008F3D4;

    switch (D_8006350C) {
    case 0:
        switch (D_80063518) {
        case 0:
            D_80126BF0->stage = 7;
            break;
        case 1:
            D_80126BF0->stage = 9;
            break;
        case 2:
            D_80126BF0->stage = 6;
            break;
        case 3:
            D_80126BF0->stage = 11;
            break;
        default:
            D_80126BF0->stage = 7;
            break;
        }
        D_801376D0 = func_80043C30() % 16;
        func_800015C4(D_80063558[D_80126BF0->stage].a, D_80063558[D_80126BF0->stage].b,
                      D_80063558[D_80126BF0->stage].c - D_80063558[D_80126BF0->stage].d);
        D_80126BF0->loaded = 1;
        func_800118D0();
        D_8006350C = 1;
        func_80043C24(D_80126BF0->timer);
        D_8008F3D4 = 0;
        break;
    case 1:
        if (D_8008F3D4++ >= 6) {
            D_8006350C = 2;
            D_8008F3D4 = 0;
        }
        break;
    case 3:
        if (func_80030F70() != 2) {
            D_8006350C = 4;
            break;
        }
    case 2:
        func_8002C8E0();
        func_8002D508();
        func_80035854();
        func_8000AAC0();
        switch (D_80063518) {
        case 0:
            func_801954A0();
            break;
        case 1:
            func_801954A0();
            break;
        case 2:
            func_801954E0();
            break;
        case 3:
            func_801954A0();
            break;
        default:
            func_801954A0();
            break;
        }
        if ((short)D_8006350C == 2) {
            if (D_8006C3D0 == 0 && D_8008F3D4 >= 0x51 && (func_80005C48() & 0x9000)) {
                func_80030E54();
                func_800485AC(10);
                D_8006350C = 3;
                D_80063514 = 4;
            }
            if (D_8008F3D4++ >= 0x47F) {
                func_80030E54();
                func_800485AC(10);
                D_8006350C = 3;
                D_80063514 = 4;
            }
        }
        break;
    case 4:
        D_80126BF0->loaded = 0;
        D_8008F3D4 = 0;
        D_80063518++;
        if (D_80063518 >= 2) {
            D_80063518 = 0;
        }
        D_8006350C = 0;
        func_80001B7C(D_80063514);
        break;
    default:
        D_8006350C = 0;
        break;
    }
}
