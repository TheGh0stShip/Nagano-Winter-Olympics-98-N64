extern unsigned char D_8013750D;
extern void func_8002D79C(void);
extern void func_8002D670(void);
extern int func_8002D7E4(void);
extern int func_8002D878(void);
extern int func_8002D8E0(void);
extern void func_8002D960(void);

int func_8002D418(void) {
    int result;

    switch (D_8013750D) {
    case 0:
        result = 0;
        func_8002D79C();
        func_8002D670();
        D_8013750D++;
        break;
    case 1:
        result = 0;
        if (func_8002D7E4()) {
            D_8013750D++;
        }
        break;
    case 2:
        result = 1;
        if (func_8002D878()) {
            D_8013750D++;
        }
        break;
    case 3:
        result = 2;
        if (func_8002D8E0()) {
            D_8013750D++;
        }
        break;
    default:
        result = 3;
        func_8002D960();
        break;
    }
    return result;
}
