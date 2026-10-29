extern unsigned char D_801373A0[];
extern unsigned char D_801374B2;
extern void func_8000EDB8(void *);

void func_8002810C(void) {
    int row;
    int column;

    if (D_801374B2 == 11) {
        for (row = 0; row < 16; row = (unsigned short)(row + 1)) {
            for (column = 0; column < 9; column = (unsigned short)(column + 1)) {
                D_801373A0[row * 9 + column + 2] = 32;
            }
            D_801373A0[row + 0x92] = 0;
            for (column = 0; column < 7; column = (unsigned short)(column + 1)) {
                D_801373A0[row * 7 + column + 0xA2] = 0;
            }
        }
        D_801373A0[1] = 0;
        D_801373A0[0] = 0;
        func_8000EDB8(D_801373A0);
    }
}
