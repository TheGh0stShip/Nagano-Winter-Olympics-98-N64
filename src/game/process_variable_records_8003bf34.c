extern unsigned char *D_80126BF0;
extern unsigned char D_80072AFC;
extern void func_8003EA20(int value);

int func_8003BF34(int start, int mode) {
    int i;
    int count = 3;

    if (mode == 1) {
        count = 8;
    }
    if (D_80126BF0[0x977F1] == 0x15 && D_80072AFC == 0) {
        count++;
    }
    for (i = 0; i < count; i++) {
        func_8003EA20(start);
        start++;
    }
    return start;
}
