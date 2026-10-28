extern int func_8003A81C(int value, int index);
extern signed char D_8013820C;

int func_8003A5C8(int value, int index, int count) {
    int i;

    D_8013820C = value;
    for (i = 0; i < count; i++) {
        value = func_8003A81C(value, index + i);
    }
    return value;
}
