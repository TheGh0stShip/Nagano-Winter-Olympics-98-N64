extern unsigned int D_80136704;
extern signed short D_8006F7C6;
extern void *func_8000F90C(void);
extern void func_8000A470(unsigned int count, signed int value,
                          float scale, float initial,
                          float extra, void *resource);

void func_8001DD08(void) {
    void *resource;

    if (D_80136704 != 1) {
        resource = func_8000F90C();
        func_8000A470(100, D_8006F7C6, 200.0f, 0.0f, 0.0f, resource);
        D_80136704 = 1;
    }
}
