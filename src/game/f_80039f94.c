extern float func_80039ACC(float c);
extern float D_801381C0[];
extern unsigned char D_801381E8[];
extern int D_80072AF4;
extern double D_800806C0;

int func_80039F94(int a, int b, float c) {
    float f;
    int r = 0;

    f = func_80039ACC(c);
    if (b >= 0) {
        D_801381C0[a] = (1.0f - f) * 280.0f + -120.0f;
    } else {
        D_801381C0[a] = (1.0f - f) * -280.0f + -120.0f;
    }
    if (c >= D_800806C0) {
        r = 1;
    }
    if (c <= 0.0f) {
        r++;
    }
    D_801381E8[a] = D_80072AF4 * f;
    return r;
}
