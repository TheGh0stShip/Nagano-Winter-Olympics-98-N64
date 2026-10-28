extern unsigned char D_80072AF8;
extern unsigned long long D_80137880;
extern unsigned long long D_8007C990;
extern short D_801378A8;
extern unsigned long long func_8004F088(unsigned long long a, unsigned long long b);
extern unsigned long long func_8004EF88(unsigned long long a, unsigned long long b);
extern void func_8005C810(unsigned long long value);

void func_800365C0(void) {
    if (D_80072AF8) {
        func_8005C810(func_8004EF88(func_8004F088(func_8004F088(D_80137880, 1000), D_8007C990), 1000000));
        D_801378A8 = 0;
    }
}
