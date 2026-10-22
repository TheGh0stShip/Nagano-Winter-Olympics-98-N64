typedef unsigned char u8;
typedef unsigned short u16;
extern u8 D_801374B2;
extern void func_8002B624(void);
extern void func_8002AF6C(u16, u8);
void func_8002AF3C(u16 value) {
    func_8002B624();
    func_8002AF6C(value, D_801374B2);
}
