extern char D_8006F938[];
extern int D_801366E8;
extern float D_801366EC;
extern double D_8007ED48;
extern unsigned char D_801366F8;
extern int D_801366FC;
extern int D_801366E0;
extern void func_8001D808(char *, int);
extern void func_8001E1C8(int);
extern void func_8001E18C(float);
extern void func_8001E158(void);

int func_8001D708(void) {
    func_8001D808(D_8006F938, D_801366E8);
    if (D_801366EC >= D_8007ED48) {
        func_8001E1C8(2);
    }
    if (D_801366EC >= 150.0f) {
        if (!D_801366F8) {
            func_8001E18C(1.0f);
            func_8001E158();
            D_801366F8 = 1;
        }
        if (D_801366FC == 0) {
            D_801366E0 = 3;
            return 1;
        }
    }
    return 0;
}
