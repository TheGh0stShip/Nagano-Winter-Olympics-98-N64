extern unsigned char D_801374B2;
extern float D_801374B4;
extern float D_801372E0;
extern float D_801374B8;
extern void func_8002B624(void);
extern void func_8002A9B0(void);

float func_8002AACC(void) {
    func_8002B624();
    if (D_801374B2 == 11) {
        return D_801374B4;
    }
    if (D_801374B2 != 7) {
        return D_801372E0;
    }
    func_8002A9B0();
    return D_801374B8;
}
