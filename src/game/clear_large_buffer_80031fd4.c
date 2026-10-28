extern unsigned char *D_80126BF0;

void func_80031FD4(void) {
    int i;

    for (i = 0; i < 15000; i++) {
        D_80126BF0[0x92C78 + i] = 0;
    }
}
