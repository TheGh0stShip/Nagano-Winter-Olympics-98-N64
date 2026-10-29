extern unsigned char *D_80126BF0;
extern signed char D_8013821A;
extern unsigned char D_80138214;
extern float D_801381E0;
extern int D_801379C8;

extern int func_8003C6B4(int);
extern void func_80048AF4(int);
extern void func_80039A8C(void);
extern void func_80038E88(int);
extern void func_8003A120(void);
extern int func_8003B694(int, int);
extern void func_8003A5C8(int, int, int);
extern void func_8003C0F0(void);

int func_8003C3C4(int arg) {
    int pad[2]; int result;
    result = func_8003C6B4(2);
    if (result == 2) {
        return 2;
    }
    func_80048AF4(0);
    D_80138214 = 2;
    func_80039A8C();
    D_8013821A = arg;
    D_801381E0 = D_8013821A * 18;
    func_80038E88(*(D_80126BF0 + 0x977EC));
    func_8003A120();
    D_801379C8 = 0;
    func_8003A5C8(func_8003B694(25, 1), D_8013821A, 6);
    func_8003C0F0();
    return result;
}
