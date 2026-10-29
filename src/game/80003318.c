extern short D_8006350C;
extern unsigned char D_80063500;
extern void func_800138C4(void);
extern void func_80011600(void);
extern int func_8001161C(void);
extern void func_80001B7C(int arg);
extern int func_8001177C(void);
extern void func_8001160C(void);

void func_80003318(void) {
    int result;

    switch (D_8006350C) {
    case 0:
        D_80063500 = 1;
        func_800138C4();
        func_80011600();
        D_8006350C = 2;
        break;
    case 2:
        result = func_8001161C();
        if (result > 0) {
            D_8006350C = 3;
            func_80011600();
        } else if (result < 0) {
            func_80001B7C(6);
            D_80063500 = 0;
        }
        break;
    case 3:
        if (func_8001177C()) {
            D_8006350C = 2;
            func_8001160C();
        }
        break;
    default:
        D_8006350C = 2;
        break;
    }
}
