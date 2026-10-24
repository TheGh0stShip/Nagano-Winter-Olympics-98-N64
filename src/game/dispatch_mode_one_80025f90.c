extern void func_80025FD8(int, int, int, int);
extern void func_800262A0(int, int, int, int);

void func_80025F90(int arg0, int arg1, int arg2, int mode) {
    switch (mode) {
        case 1:
            func_80025FD8(arg0, arg1, arg2, mode);
            break;
        case 0:
        default:
            func_800262A0(arg0, arg1, arg2, mode);
            break;
    }
}
