extern int func_8003C6B4(void);
extern void func_8003D218(signed char value);
extern void func_80039A8C(void);
extern void func_8003DCBC(void);
extern signed char D_80138214;
extern signed char D_8013821E;

int func_8003D1B0(int value) {
    long long unused;
    int current;

    current = func_8003C6B4();

    if (current == value) {
        return value;
    }
    D_80138214 = value;
    D_8013821E = 0;
    func_8003D218(D_8013821E);
    func_80039A8C();
    func_8003DCBC();
    return current;
}
