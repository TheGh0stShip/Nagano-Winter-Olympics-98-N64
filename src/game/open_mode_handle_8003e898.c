extern unsigned char *D_80126BF0;
extern int func_8003BEE4(int id);
extern int func_8003BF34(int id, int arg1);
extern void func_8003C5C8(int handle, signed char arg1, int arg2);
extern signed char D_8013821A;
extern unsigned char D_80072AFC;

void func_8003E898(void) {
    int handle;

    if (D_80126BF0[0x977F1] == 21) {
        handle = func_8003BEE4(25);
    } else {
        handle = func_8003BF34(25, 0);
    }
    func_8003C5C8(handle, D_8013821A, 3);
    D_80072AFC = 0;
}
