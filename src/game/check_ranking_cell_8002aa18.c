extern unsigned char D_801374B2;
extern unsigned char D_801374C9;
extern unsigned char *D_80126BF0;
extern signed char D_80071A5C[];
extern unsigned char D_80137260[];
extern unsigned char func_8002B4B4(void);
extern void func_8002B624(void);

int func_8002AA18(void) {
    unsigned char row = func_8002B4B4();
    unsigned char value;
    unsigned char *cells;

    func_8002B624();
    if (D_801374B2 == 11) {
        cells = &D_80137260[row * 7];
        value = cells[D_80071A5C[D_80126BF0[0x977EC]]];
        if (value == 0) {
            if (D_801374C9 == 1) {
                value = 0;
            } else {
                value++;
            }
        }
    } else {
        value = row;
    }
    if (value == 0) {
        return 1;
    }
    return 0;
}
