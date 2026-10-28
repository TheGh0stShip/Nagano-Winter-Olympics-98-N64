extern float D_801366E8;
extern float D_801366EC;
extern unsigned char D_8006F938[];
extern int func_8001D808(unsigned char *table, float value);
extern void func_8001E158(void);

int func_8001D668(void) {
    D_801366E8 = D_801366EC * 0.214f - 240.0f;
    if (func_8001D808(D_8006F938, D_801366E8) == 0) {
        func_8001E158();
        return 1;
    }
    if (D_801366E8 >= 2198.0f) {
        D_801366EC = 0;
        return 1;
    }
    return 0;
}
