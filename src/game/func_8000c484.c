extern unsigned char D_8008F3C8;
extern unsigned short D_801335AC;
extern int D_801335B0;
extern int D_80136C84;
extern unsigned char D_800639A0[];
extern void func_8000C190(void *arg0);
extern void func_8000C5AC(void);
extern int func_8000C5E4(void);

int func_8000C484(void) {
    int result;

    switch (D_801335AC) {
    case 0:
        D_8008F3C8 = 1;
        func_8000C190(D_800639A0);
        D_8008F3C8 = 0;
        D_801335AC = 1;
        break;
    case 1:
        if (D_801335B0++ >= 9) {
            D_801335AC = 2;
            D_801335B0 = 0;
        }
        break;
    case 2:
        D_80136C84 = 0;
        func_8000C5AC();
        D_801335AC = 3;
        break;
    case 3:
        result = func_8000C5E4();
        if (result == 0) {
            D_801335AC = 4;
        }
        if (result < 0) {
            D_801335AC = 5;
        }
        break;
    case 4:
        D_801335AC = 2;
        return 0;
    case 5:
        D_801335AC = 2;
        return -1;
    default:
        D_801335AC = 4;
        break;
    }
    return 1;
}
