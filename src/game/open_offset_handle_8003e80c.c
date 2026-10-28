extern unsigned char *D_80126BF0;
extern int func_8003B984(int id);
extern int func_8003BAD0(int id, int arg1);
extern void func_8003E75C(int *first, int *second);
extern void func_8003C498(int handle, signed char arg1, int arg2, int arg3);
extern signed char D_8013821A;

void func_8003E80C(void) {
    int handle;
    int first = 1;
    int second = -154;

    if (D_80126BF0[0x977F1] == 21) {
        handle = func_8003B984(25);
    } else {
        handle = func_8003BAD0(25, 0);
    }
    func_8003E75C(&first, &second);
    func_8003C498(handle, D_8013821A, first, second);
}
