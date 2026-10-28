extern unsigned char *D_80126BF0;
extern unsigned char D_80136718[];
extern unsigned char D_801367C0[];
extern unsigned char D_80136980[];
extern unsigned char D_80136828;
extern unsigned char D_80136960;
extern unsigned char D_80136824;
extern void func_80003C10(unsigned char *dst, int count);
extern void func_8001F2C8(unsigned char *first, unsigned char *second);

void func_8001F54C(void) {
    D_80126BF0[0x977F6] = 0;
    func_80003C10(D_80136718, 0x80);
    func_80003C10(D_801367C0, 0x1C0);
    func_80003C10(D_80136980, 0x6C);
    D_80136828 = 0;
    D_80136960 = 0;
    D_80136824 = 0; func_8001F2C8(D_801367C0, D_80136980);
}
