extern unsigned char D_801374B2;
extern void func_8002B624(int);
extern void func_8002AEA4(int, unsigned char);

void func_80028220(int value) {
    unsigned char state;

    func_8002B624(value);
    state = D_801374B2;
    if (state == 11) {
        func_8002AEA4(value, state);
    }
}
