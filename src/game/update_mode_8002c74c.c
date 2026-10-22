typedef unsigned char u8;
extern u8 func_8002C800(int);
extern void func_800127A4(void);
u8 func_8002C74C(void) {
    u8 result = func_8002C800(4);
    if (result == 3) func_800127A4();
    return result;
}
