extern unsigned char D_801374B2;
extern unsigned char *D_80126BF0;
extern void func_8002B624(void);
extern unsigned int func_80046280(unsigned char course, float value);

float func_80029C18(float *value) {
    func_8002B624();
    if (D_801374B2 == 11) {
        if (*value == -1.0f) {
            return 0.0f;
        }
        return func_80046280(D_80126BF0[0x977EC], *value);
    }
    return *value;
}
