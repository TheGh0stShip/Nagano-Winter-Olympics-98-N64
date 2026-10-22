extern void func_8003EA20(int);

int func_8003AEF4(int start) {
    int i;
    int count = 5;

    for (i = 0; i < count; i++) {
        func_8003EA20(start);
        start++;
    }
    return start;
}
