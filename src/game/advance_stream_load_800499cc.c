extern unsigned char D_801796FE;
extern unsigned short D_801796FC;
extern unsigned char D_801796D1;
extern unsigned char D_8008F3C8;
extern unsigned char *D_800736F8[];
extern unsigned char *D_80073754[];
extern unsigned char D_8018D680[];
extern void func_8000BB14(unsigned char *src, unsigned char *dst, int size);
extern void func_80049A78(unsigned short id, int value);

void func_800499CC(void) {
    unsigned short index;

    if (--D_801796FE == 0) {
        if (D_8008F3C8 != 0) {
            D_801796FE = 1;
        } else {
            index = D_801796FC - 16;
            D_801796D1 = D_801796FC;
            func_8000BB14(D_800736F8[index], D_8018D680, D_80073754[index] - D_800736F8[index]);
            func_80049A78(D_801796FC, 5);
            D_801796FC = 0;
        }
    }
}
