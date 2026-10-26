extern unsigned char *D_80126BF0;
extern float D_80080110;
extern float D_801374B8;
extern void func_8002B624(void);
extern void func_8002A898(void);
extern void func_8002A948(void);

void func_8002A9B0(void) {
    func_8002B624();
    if (D_80126BF0[0x977F2] == 0) {
        D_801374B8 = D_80080110;
        func_8002A898();
        func_8002A948();
    } else {
        func_8002A898();
    }
}
