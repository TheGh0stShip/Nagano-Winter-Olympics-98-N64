extern unsigned char D_80072AF8;
extern short D_801378A8;
extern unsigned char D_80137870;
extern void func_8005C810(unsigned long long value);

void func_80037074(void) {
    if (D_80072AF8) {
        D_801378A8 = 0;
        func_8005C810(0);
        D_80137870 = 1;
    }
}
