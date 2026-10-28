extern unsigned char D_80072AF8;
unsigned long long D_80137880;
extern unsigned long long D_8007C990;
extern void func_8005C810(unsigned long long value);

void func_80036654(unsigned long long time) {
    if (D_80072AF8) {
        func_8005C810(time * 1000 * D_8007C990 / 1000000);
        D_80137880 = time;
    }
}
