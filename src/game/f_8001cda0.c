extern char D_80063948[];
extern int D_801366E0;
extern void func_80007F90(int, char *);
extern int func_8001CE6C(void);
extern void func_8001CE8C(void);
extern void func_8001CE98(void);
extern void func_8001CEB8(void);

int func_8001CDA0(void) {
    func_80007F90(1, D_80063948);
    switch (D_801366E0) {
    case 0:
        if (func_8001CE6C()) {
            D_801366E0 = 1;
        }
        break;
    case 1:
        func_8001CE8C();
        D_801366E0 = 2;
        break;
    case 2:
        func_8001CE98();
        return 0;
    case 3:
        func_8001CEB8();
        D_801366E0 = 0;
        return -1;
    default:
        D_801366E0 = 3;
        break;
    }
    return 0;
}
