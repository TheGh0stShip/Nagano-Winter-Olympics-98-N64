extern void func_80031ED0(void);
extern void func_80031F84(void);

void func_80031E7C(unsigned char mode) {
    if (mode != 0) {
        if (mode == 1) {
            func_80031ED0();
        }
    } else {
        func_80031F84();
    }
}
