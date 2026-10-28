extern unsigned char D_80138214;
extern unsigned char D_80138217;
extern unsigned char D_801380B8;
extern void func_8002C3F4(void);

int func_80039A00(void) {
    if (D_80138214 == 2 && D_80138217 == 0) {
        func_8002C3F4();
    }
    D_80138217 = 1;
    if (D_801380B8 == 0) {
        return 1;
    }
    if (D_801380B8 == 5) {
        return 2;
    }
    if (D_801380B8 == 6) {
        return 3;
    }
    return 2;
}
