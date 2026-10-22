extern void func_80013374(unsigned short);

void func_80013404(void) {
    short i;

    for (i = 0; i < 160; i++) {
        func_80013374(i);
    }
}
