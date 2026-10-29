typedef struct Channel {
    int active;
    unsigned char pad[0xCC];
} Channel;

extern int D_8017992C;
extern unsigned char D_80179930;
extern unsigned char D_80179740[];
extern unsigned char D_80179741[];
extern unsigned char D_8017975A[];
extern unsigned char D_801796D0;
extern unsigned char D_80179684[];
extern int D_801796F8;
extern unsigned char D_80179676;
extern unsigned char D_8017967E[];
extern unsigned short D_80179680[];
extern Channel D_8018C980[];
extern int func_8004A560(int);
extern void func_80049F88(void);

void func_80049E20(void) {
    int i;

    D_8017992C = 0;
    D_80179930 = 0;
    for (i = 0; i < 1; i++) {
        D_80179740[i] = 0;
        D_80179741[i] = 0;
        D_8017975A[i] = 0;
    }
    D_801796D0 = 0;
    D_80179684[0] = D_80179684[1] = 0;
    if (D_801796F8 == 1) {
        D_80179676 = 0;
    }
    for (i = 0; i < 16; i++) {
        if (D_80179676 != 0) {
            if (func_8004A560(i) != 0) {
                D_8018C980[i].active = 16;
            }
        } else {
            D_8018C980[i].active = 16;
        }
    }
    D_80179676 = 0;
    func_80049F88();
    for (i = 0; i < 2; i++) {
        D_80179680[i] = D_8017967E[i] = 0;
    }
}
