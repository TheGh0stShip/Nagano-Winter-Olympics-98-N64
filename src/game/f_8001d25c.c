extern float D_801366EC;
extern float D_8007ED38;
extern void func_8001DF60(int index, float first, float second);
extern void func_8001E158(void);

int func_8001D25C(void) {
    float t;


    t = -D_801366EC * D_8007ED38;

    func_8001DF60(3, (int)t, 0.0f);
    func_8001DF60(5, (int)t + 320, 0.0f);
    if (t < -160.0f) {
        func_8001E158();
        return 1;
    }
    return 0;
}
