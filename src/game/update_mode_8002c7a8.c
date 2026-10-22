typedef unsigned char u8;
extern u8 func_8002C800(int);
extern void func_80012788(void);
u8 func_8002C7A8(void) {
    u8 result = func_8002C800(2);
    if (result == 0) func_80012788();
    return result;
}
