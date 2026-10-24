extern unsigned char *D_80126BF0;
extern unsigned char D_80063504;
extern unsigned char D_8008F3D0;
extern void func_800138C4(void);
extern void func_80007E5C(void);
extern void func_80030908(void);

void func_80001C00(void) {
    *(unsigned short *)(D_80126BF0 + 0x7C8CA) = 0;
    D_80063504 = 1;
    D_8008F3D0 = 0;
    func_800138C4();
    func_80007E5C();
    func_80030908();
}
