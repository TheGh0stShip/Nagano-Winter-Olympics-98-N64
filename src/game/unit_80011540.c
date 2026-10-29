typedef struct Rec {
    int a;
    int b;
    int c;
    int d;
} Rec;

extern Rec D_80063558[];
extern unsigned char *D_80126BF0;
extern unsigned short D_80134080;
extern unsigned char D_8008F3C8;
extern void func_800015C4(int, int, int);

extern unsigned short D_80134090;
extern unsigned short D_80134092;
extern unsigned char func_8001180C(unsigned char);
extern int func_80007170(int);
extern void func_801954A0(void);
extern void func_8019554C(void);
extern signed char func_80195C74(void);
extern void func_8003C768(void);
extern void func_8003CA38(void);
extern int func_80039788(void);

unsigned char func_80011540(unsigned char index) {
    unsigned char result = 0;
    unsigned int i = index;

    if (i != 0) {
        D_8008F3C8 = 1;
        func_800015C4(D_80063558[i + 11].a, D_80063558[i + 11].b,
                      D_80063558[i + 11].c - D_80063558[i + 11].d);
        D_8008F3C8 = 0;
        D_80134080 = *(unsigned short *)(D_80126BF0 + 0x7C8D8);
    } else if (*(unsigned short *)(D_80126BF0 + 0x7C8D8) - D_80134080 >= 8) {
        result = 1;
    }
    return result;
}

void func_80011600(void) {
    D_80134090 = 0;
}

void func_8001160C(void) {
    D_80134090 = 6;
}

signed char func_8001161C(void) {
    signed char result = 0;

    switch (D_80134090) {
        case 0:
            func_8001180C(2);
            D_80134090 = 1;
            break;
        case 1:
            if (func_8001180C(0)) {
                D_80134092 = 0;
                D_80134090 = 2;
            }
            break;
        case 2:
            if (D_80134092 == 0) {
                if (func_80007170(14)) {
                    D_80134092++;
                }
            } else if (D_80134092++ > 0) {
                D_80134090 = 5;
            }
            break;
        case 5:
            func_801954A0();
            D_80134090 = 10;
            break;
        case 6:
            func_8019554C();
            D_80134090 = 10;
            break;
        case 10:
            result = func_80195C74();
            if (result != 0 && result != -1) {
                D_80134090 = 20;
                result = 0;
            }
            break;
        case 20:
            result = 1;
            break;
        default:
            D_80134090 = 0;
            break;
    }
    return result;
}

signed char func_8001177C(void) {
    signed char done = 0;

    switch (D_80134090) {
        case 0:
            D_80134090 = 10;
            func_8003C768();
            func_8003CA38();
            break;
        case 10:
            if (func_80039788() == 1) {
                D_80134090 = 20;
            }
            break;
        case 20:
            done = 1;
            break;
        default:
            D_80134090 = 0;
            break;
    }
    return done;
}

unsigned char func_8001180C(unsigned char index) {
    unsigned char result = 0;
    unsigned int i = index;

    if (i != 0) {
        D_8008F3C8 = 1;
        func_800015C4(D_80063558[i + 11].a, D_80063558[i + 11].b,
                      D_80063558[i + 11].c - D_80063558[i + 11].d);
        D_8008F3C8 = 0;
        D_80134092 = *(unsigned short *)(D_80126BF0 + 0x7C8D8);
    } else if (*(unsigned short *)(D_80126BF0 + 0x7C8D8) - D_80134092 >= 8) {
        result = 1;
    }
    return result;
}
