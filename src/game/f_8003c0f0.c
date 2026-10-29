extern unsigned char D_80138214;
extern unsigned char D_801380B8;
extern signed char D_8013821A;
extern unsigned char D_8013820C;
extern unsigned char *D_80126BF0;
extern float D_801381F8;
extern float D_80138204;
extern float D_800806CC;
extern double D_800806F8;
extern float D_80080700;
extern int func_8003DCBC(void);
extern void func_8003C3C4(int);
extern int func_80039B24(void);
extern unsigned int func_8003CBA0(int, int);
extern void func_8003CF4C(int);
extern int func_8003CC78(void);
extern void func_8003C5C8(int, int, int);
extern void func_8003CD94(int);
extern void func_8003CFE4(int);
extern int func_8003D06C(void);
extern float func_8003CE68(void);
extern void func_8003C67C(void);
extern void func_8003D190(void);
extern void func_8003CECC(void);
extern void func_8003C55C(void);
extern void func_8003B044(int);

int func_8003C0F0(void) {
    int result = 0;
    unsigned int flags;

    if (D_80138214 == 7) {
        if (func_8003DCBC() == 1) {
            func_8003C3C4(D_8013821A);
            D_801381F8 = D_800806CC;
            func_80039B24();
            D_801380B8 = 9;
        } else {
            return 0;
        }
    }
    switch (D_801380B8) {
    case 0:
        D_801381F8 = D_801381F8 + D_800806F8;
        if (func_80039B24() == 0) {
            D_801380B8 = 1;
        }
        break;
    case 1:
        flags = func_8003CBA0(10, 4);
        if (D_80126BF0[0x977F1] == 21) {
            if (flags & 0x1000000) {
                D_80138204 = D_80080700;
                D_801380B8 = 7;
            }
        }
        break;
    case 2:
        func_8003CF4C(6);
        break;
    case 3:
        if (func_8003CC78() != 0) {
            func_8003C5C8(D_8013820C, D_8013821A, 6);
            func_8003CD94(6);
        }
        break;
    case 4:
        func_8003CFE4(6);
        break;
    case 5:
        if (func_8003D06C() != 0) {
            result = 1;
        }
        break;
    case 7:
        if (func_8003CE68() >= 1.0f) {
            func_8003C67C();
            func_8003D190();
            return 0;
        }
        break;
    case 9:
        func_8003CECC();
        break;
    default:
        break;
    }
    func_8003C55C();
    if (result == 1) {
        func_8003C67C();
        func_8003B044(25);
    }
    return result;
}
