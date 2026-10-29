extern unsigned char D_801381F1;
extern signed char D_8013821A;
extern unsigned char *D_80126BF0;
extern int func_8003B5AC(int);
extern void func_8003EA20(int);
extern int func_8003BF34(int, int);
extern void func_8003C5C8(int, int, int);

void func_8003969C(void) {
    int index;
    int i;
    int result;

    index = func_8003B5AC(25);
    func_8003EA20(index++);
    for (i = 0; i < D_801381F1; i++) {
        func_8003EA20(index);
        index++;
    }
    result = func_8003BF34(index, 0);
    if (D_80126BF0[0x977F1] != 21) {
        func_8003C5C8(result, D_8013821A, 5);
    }
}
