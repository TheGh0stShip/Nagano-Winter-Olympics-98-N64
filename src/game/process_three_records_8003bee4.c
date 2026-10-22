extern void func_8003EA20(int);

int func_8003BEE4(int start) {
    int i;
    for (i = 0; i != 3; i++) {
        func_8003EA20(start);
        start++;
    }
    return start;
}
