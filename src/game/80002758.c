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
    unsigned char pad7C8DA[0x16];
    unsigned char unk7C8F0;
    unsigned char pad7C8F1;
    unsigned char unk7C8F2;
    unsigned char pad7C8F3[0x36E5];
    InitBlock init;
    unsigned char pad80050[0x1779C];
    unsigned char stage;
    unsigned char pad977ED[0x6];
    unsigned char unk977F3;
    unsigned char pad977F4[0x3];
    unsigned char unk977F7;
    unsigned char unk977F8;
} Runtime;

extern InitBlock D_800690E0;
extern InitBlock D_80069158;
extern Rec D_80063558[];
extern Runtime *D_80126BF0;
extern unsigned short D_8006350C;
extern unsigned char D_80063500;
extern unsigned char D_80063504;
extern unsigned char D_8008F3C8;
extern int D_801386AC;
extern void func_800138C4(void);
extern void func_80010800(void);
extern int func_80010874(void);
extern void func_8001085C(void);
extern int func_80010A20(void);
extern void func_80010814(void);
extern void func_800127BC(void);
extern void func_80007E5C(void);
extern void func_800118D0(void);
extern int func_800125D4(void);
extern void func_800485AC(int arg);
extern int func_800119B8(void);
extern void func_80001B7C(int arg);
extern void func_800306CC(void);
extern int func_8002B414(void);
extern int func_8000FA1C(void);
extern void func_8002D980(unsigned char arg);
extern int func_8002D998(void);
extern void func_800015C4(int, int, int);
extern void func_801954A0(void);
extern int func_80199954(void);
extern void func_8001CED8(void);
extern int func_8001CDA0(void);

void func_80002758(void) {
    static unsigned char D_8008F3DA;
    static unsigned char D_8008F3DB;
    int result;

    switch (D_8006350C) {
    case 0:
        func_800138C4();
        D_80063500 = 1;
        D_8008F3DA = 0;
        func_80010800();
        D_8006350C = 1;
        break;
    case 1:
        D_80063500 = 1;
        if (D_8008F3DA++ >= 8) {
            D_8008F3DA = 0;
            func_80010800();
            D_8006350C = 2;
        }
        break;
    case 2:
        D_80063500 = 1;
        D_80126BF0->init = D_80069158;
        result = func_80010874();
        if (result > 0) {
            D_8006350C = 4;
        }
        if (result < 0) {
            func_80001B7C(6);
        }
        break;
    case 4:
        D_80063500 = 1;
        func_80010800();
        D_8006350C = 3;
        break;
    case 5:
        D_80063500 = 1;
        func_8001085C();
        D_8006350C = 3;
        break;
    case 3:
        D_80126BF0->init = D_80069158;
        result = func_80010A20();
        if (result > 0) {
            D_8006350C = 10;
        }
        if (result < 0) {
            D_8006350C = 2;
            func_80010814();
        }
        break;
    case 10:
        D_80063500 = 0;
        D_80126BF0->unk977F8 = 0;
        func_800127BC();
        func_800138C4();
        func_80007E5C();
        func_800118D0();
        D_8006350C = 11;
        break;
    case 11:
        D_80126BF0->init = D_800690E0;
        if (func_800125D4()) {
            switch (D_80126BF0->unk7C8F2) {
            case 0:
                break;
            case 1:
                D_80126BF0->unk977F7 = 1;
                func_800485AC(1);
                D_80126BF0->unk7C8F0 = 0;
                break;
            case 2:
                break;
            }
            func_800119B8();
        } else {
            if (func_800119B8() < 0) {
                func_80001B7C(1);
            }
            if (D_80126BF0->unk977F3) {
                func_800306CC();
                D_80126BF0->unk977F3 = 0;
                if (D_80126BF0->stage == 11) {
                    if (D_801386AC) {
                        D_8006350C = 25;
                    } else {
                        D_8006350C = 30;
                    }
                } else if (func_8002B414()) {
                    D_8006350C = 25;
                } else {
                    D_8006350C = 30;
                }
            }
        }
        break;
    case 25:
        func_800138C4();
        func_80007E5C();
        func_8002D980(func_8000FA1C());
        D_8006350C = 26;
        break;
    case 26:
        result = func_8002D998();
        if (result == 2) {
            D_8006350C = 40;
        } else if (result == 1) {
            D_8006350C = 30;
        }
        break;
    case 30:
        func_800127BC();
        func_800138C4();
        func_80007E5C();
        D_8006350C = 31;
        D_8008F3DA = 0;
        break;
    case 31:
        if (D_8008F3DA == 0) {
            D_8008F3C8 = 1;
            func_800015C4(D_80063558[17].a, D_80063558[17].b, D_80063558[17].c - D_80063558[17].d);
            D_8008F3C8 = 0;
            D_8008F3DB = D_80126BF0->timer;
            D_8008F3DA = 1;
        } else if (D_8008F3DA == 1) {
            if (D_80126BF0->timer - D_8008F3DB >= 8) {
                func_801954A0();
                D_8008F3DA = 2;
            }
        } else {
            switch (func_80199954()) {
            case 1:
                D_8006350C = 10;
                break;
            case 2:
                D_8006350C = 5;
                break;
            case 3:
                D_8006350C = 0;
                func_80001B7C(6);
                break;
            }
        }
        break;
    case 40:
        D_80063504 = 1;
        func_800127BC();
        func_800138C4();
        func_8001CED8();
        func_80007E5C();
        D_8006350C = 41;
        break;
    case 41:
        if (func_8001CDA0()) {
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
