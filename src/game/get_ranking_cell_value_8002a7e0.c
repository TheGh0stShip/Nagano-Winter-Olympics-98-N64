extern unsigned char D_801374B2;
extern unsigned char *D_80126BF0;
extern signed char D_80071A5C[];
extern unsigned char D_801371F0[];
extern unsigned char func_8002B4B4(void);
extern void func_8002B624(void);

float func_8002A7E0(void) {
    unsigned char row = func_8002B4B4();
    unsigned char *cells;

    func_8002B624();
    if (D_801374B2 != 11) {
        return 0.0f;
    }
    cells = &D_801371F0[row * 7];
    return (unsigned int)cells[D_80071A5C[D_80126BF0[0x977EC]]];
}
