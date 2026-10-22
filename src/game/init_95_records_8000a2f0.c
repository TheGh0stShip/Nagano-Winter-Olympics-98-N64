extern void func_8000A1DC(short);

void func_8000A2F0(void) {
    short i;

    for (i = 0; i < 95; i++) {
        func_8000A1DC(i);
    }
}
