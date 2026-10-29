extern signed char D_8017966E;
extern unsigned char D_80179676;
extern unsigned char D_80179673;
extern signed char D_8017967B;
extern unsigned short D_80179680[2];
extern unsigned int *D_80179924;
extern void func_8004B3E0(void);

void func_8004B0F4(void) {
    unsigned int key;
    unsigned short *p;
    unsigned short *end;

    if (D_8017966E != 0) {
        func_8004B3E0();
        return;
    }
    if (D_80179676 != 0) {
        func_8004B3E0();
        return;
    }
    key = *D_80179924 & 0x7FFF;
    if (key < 0x100 && (D_80179673 != 0 || D_8017967B != 0)) {
        func_8004B3E0();
        return;
    }
    for (p = D_80179680, end = D_80179680 + 2; p != end; p++) {
        if (key == *p) {
            func_8004B3E0();
            return;
        }
    }
}
