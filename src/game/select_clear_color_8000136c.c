extern unsigned char *D_80126BF0;
extern unsigned char D_80063504;
extern void func_80001BF4(void);
extern void func_80001150(int r, int g, int b, int a);

void func_8000136C(void) {
    unsigned char mode;

    func_80001BF4();
    mode = D_80126BF0[0x977F1];
    if (mode == 2 || D_80063504 != 0 || mode == 4 || mode == 0 || mode == 1 || mode == 3) {
        func_80001150(0, 0, 0, 255);
    } else {
        func_80001150(255, 255, 255, 255);
    }
}
