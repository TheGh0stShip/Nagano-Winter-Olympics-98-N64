typedef unsigned char u8;
typedef signed char s8;

extern u8 func_8002B4B4(void);
extern void func_8002B624(void);
extern u8 D_801374B2;
extern u8 *D_80126BF0;
extern s8 D_80071A5C[];
extern u8 D_80137260[];

u8 func_8002A6C4(void *unused) {
    unsigned char pad;
    u8 row = func_8002B4B4();
    u8 *cells;

    func_8002B624();
    if (D_801374B2 != 11) {
        return 0;
    }
    cells = &D_80137260[row * 7];
    return (float)(unsigned int)cells[D_80071A5C[D_80126BF0[0x977EC]]];
}
