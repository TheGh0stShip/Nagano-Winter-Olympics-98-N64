extern short func_8002C6EC(void);
extern signed char D_801374D0[];

void func_8002C460(void) {
    unsigned short i;
    short value;

    for (i = 0; i < 6; i++) {
        value = func_8002C6EC() + i;
        if (value < 0) {
            return;
        }
        D_801374D0[i] = value;
    }
}
