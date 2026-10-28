extern int D_801796F8;
extern unsigned short D_80179680[];
extern unsigned char D_8017967E[];

void func_8004A43C(void) {
    int value;
    int i;

    value = D_801796F8 &= 0x7FFF;
    for (i = 0; i < 2; i++) {
        if (value == D_80179680[i]) {
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        if (D_80179680[i] == 0) {
            D_80179680[i] = value;
            D_8017967E[i] = 0xFF;
            return;
        }
    }
}
