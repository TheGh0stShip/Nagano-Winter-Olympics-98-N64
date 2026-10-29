extern unsigned char D_80179740[];
extern unsigned char D_80179741[];
extern unsigned short D_80179748[][9];
extern unsigned char D_8017975A[];
extern unsigned int D_801796F8;
extern void func_80049470(int);

void func_80048C50(void) {
    int i;
    unsigned char *p;

    for (i = 0; i < 1; i++) {
        if (D_8017975A[i] == 0 && D_80179740[i] != 0) {
            p = &D_80179741[i];
            D_801796F8 = D_80179748[i][*p];
            D_80179740[i]--;
            (*p)++;
            if (*p >= 9) {
                *p = 0;
            }
            func_80049470(0);
        }
    }
}
