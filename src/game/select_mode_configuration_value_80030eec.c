extern void func_80030CB4(unsigned char mode, float value);
extern void func_80030D28(unsigned char mode, float value);

void func_80030EEC(unsigned char mode, float value) {
    if (mode == 2 || mode == 4) {
        func_80030CB4(mode, value);
    } else if (mode == 5 || mode == 6) {
        func_80030CB4(mode, value);
    } else {
        func_80030D28(mode, value);
    }
}
