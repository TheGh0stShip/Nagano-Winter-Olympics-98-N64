extern unsigned char D_801796D0;
extern unsigned char D_801796D2;
extern unsigned int D_801796D8[];
extern unsigned int D_801796F8;
extern void (*D_800737B0[])(void);
extern void func_800498CC(void);
extern void func_80049470(int);
extern void func_8004A43C(void);
extern void func_8004883C(int);

void func_80048B24(void) {
    int i;
    unsigned short cmd;

    i = 0;
    while (D_801796D2 != 0) {
        D_801796F8 = D_801796D8[i];
        cmd = D_801796F8 & 0xFFFF;
        i++;
        D_801796D2--;
        if (cmd < 0x100) {
            if (cmd < 0x10) {
                D_800737B0[cmd - 1]();
            } else {
                func_800498CC();
            }
        } else if (cmd < 0x8000) {
            func_80049470(0);
        } else {
            func_8004A43C();
        }
    }
    i = 0;
    while (D_801796D0 != 0) {
        func_8004883C(i);
        i++;
        D_801796D0--;
    }
}
