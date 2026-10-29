extern unsigned char D_80072AFC;
extern unsigned char D_801380B8;
extern unsigned char D_80138217;
extern float D_801381F8;
extern double D_80080828;
extern float D_80080830;
extern int func_80039B24(void);
extern int func_8003D06C(void);
extern void func_8003E80C(void);
extern void func_8003E898(void);

int func_8003E904(void) {
    int result = 0;

    if (D_80072AFC == 0) {
        return 0;
    }
    switch (D_801380B8) {
    case 0:
        D_801381F8 = D_801381F8 + D_80080828;
        if (func_80039B24() == 0) {
            D_801380B8 = 1;
        }
        break;
    case 1:
        if (D_80138217 == 1) {
            D_801381F8 = D_80080830;
            D_801380B8 = 5;
        }
        break;
    case 5:
        if (func_8003D06C() != 0) {
            result = 1;
        }
        break;
    case 6:
        return 1;
    }
    func_8003E80C();
    if (result == 1) {
        func_8003E898();
    }
    return result;
}
