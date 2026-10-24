typedef unsigned char u8;

extern u8 *D_80126BF0;
extern u8 D_801376D0[];
extern void func_80048A78(unsigned short value);
extern void func_8002B81C(unsigned short first, unsigned short second);

void func_8002B72C(void) {
    func_80048A78(0x3F4);
    func_8002B81C(0x3BF, D_801376D0[D_80126BF0[0x977EF]]);
    func_80048A78(0x3D0);
}
