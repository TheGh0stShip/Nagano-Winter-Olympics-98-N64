extern void func_800483FC(void);
extern void func_800499CC(void);
extern void func_80048D40(void);
extern void func_80048EE4(void);
extern void func_80048C50(void);
extern void func_80048B24(void);
extern void func_8004A5C4(void);

extern unsigned char D_80179668;
extern unsigned char D_80179669;
extern unsigned short D_8017966A;
extern unsigned short D_801796FC;
extern int D_8017992C;
extern unsigned char D_80179930;

int func_80048310(int arg0) {
    if (D_80179668 != 0) {
        if (D_80179668 == 8) {
            func_800483FC();
        }
        D_80179668 = D_80179668 - 1;
    } else {
        if (D_801796FC != 0) {
            func_800499CC();
        }
        if (D_8017992C != 0) {
            func_80048D40();
        }
        if (D_80179930 != 0) {
            func_80048EE4();
        }
        if (D_80179669 == 0) {
            func_80048C50();
        }
        if (D_80179669 == 0) {
            func_80048B24();
        }
        func_8004A5C4();
        D_8017966A++;
    }
    return 0x1388;
}
