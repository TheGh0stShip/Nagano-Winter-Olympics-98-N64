extern unsigned short D_80137706;
extern unsigned char D_8013770C[4];
extern void func_8003241C(void);
extern void func_800324C0(void);

int func_8003227C(void) {
    unsigned short i;

    func_8003241C();
    D_80137706 = 0;
    for (i = 0; i < 4; i++) {
        D_8013770C[i] = 0;
    }
    func_800324C0();
    return 1;
}
