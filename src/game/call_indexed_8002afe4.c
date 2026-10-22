typedef unsigned char u8;
typedef unsigned short u16;
extern u8 D_801374B2;
extern void func_8002B624(void);
extern void func_8002B014(u16, u8);
void func_8002AFE4(u16 value) {
    func_8002B624();
    func_8002B014(value, D_801374B2);
}
