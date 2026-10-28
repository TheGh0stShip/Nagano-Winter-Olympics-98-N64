extern unsigned char D_80072AF8;
extern unsigned char D_80137870;
long long D_80137880;
extern void func_80036ED0(int value);
extern void func_80037B10(void);

void func_80037348(void) {
    if (D_80072AF8) {
        D_80137870 = 0;
        D_80137880 = 0;
        func_80036ED0(0);
        func_80037B10();
    }
}
