extern unsigned char D_801374D0[];
extern void func_8002CD88(unsigned char, unsigned char);

void func_8002C8E0(void) {
    unsigned short i;
    for (i = 0; i < 6; i++) {
        func_8002CD88(D_801374D0[i], i);
    }
}
