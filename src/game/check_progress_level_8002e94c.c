extern unsigned char D_80137555;
extern void func_8003E63C(int mode);
extern int func_80039A00(void);

int func_8002E94C(unsigned char mode) {
    unsigned char next;

    if (mode != 5) {
        next = mode;
        if (D_80137555 == 11 && mode == 3) {
            next = 5;
        }
        if (D_80137555 == 11 && mode == 4) {
            next = 6;
        }
        func_8003E63C(next);
        return 0;
    }
    if (func_80039A00() >= 3) {
        return 1;
    }
    return 0;
}
