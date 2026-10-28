extern unsigned char *D_80126BF0;
extern void func_8002B0FC(unsigned char first, unsigned char second);

void func_800297A8(void) {
    unsigned char n;
    if (D_80126BF0[0x977F2]) {
        func_8002B0FC(0, 15);
        n = 16 - D_80126BF0[0x977F0];
        n += D_80126BF0[0x977EF];
        n++;
        func_8002B0FC(n, 15);
    }
    n = 16 - D_80126BF0[0x977F0];
    n += D_80126BF0[0x977EF];
    func_8002B0FC(0, n);
}
