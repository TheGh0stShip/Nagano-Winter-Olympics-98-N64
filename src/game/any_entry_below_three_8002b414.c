extern unsigned char *D_80126BF0;
extern int func_8002B5D0(unsigned char index);

int func_8002B414(void) {
    int found = 0;
    unsigned char i;

    for (i = 0; i < D_80126BF0[0x977F0]; i++) {
        if (func_8002B5D0(i) < 3) {
            found = 1;
        }
    }
    return found;
}
