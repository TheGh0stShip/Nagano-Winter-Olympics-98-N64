extern void func_80009900(short);

void func_80009AA0(void) {
    short i;

    for (i = 0; i < 2; i++) {
        func_80009900(i);
    }
}
