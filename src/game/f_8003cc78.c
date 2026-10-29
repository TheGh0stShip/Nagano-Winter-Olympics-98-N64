extern float func_80039ACC(float);
extern float D_801381FC;
extern float D_801381E0;
extern signed char D_8013821A;
extern signed char D_8013821B;

int func_8003CC78(void) {
    float f;

    D_801381FC += 0.3769911334110563;
    if (D_801381FC >= 1.5707963267948966) {
        D_801381FC = 1.57079637f;
    }
    f = func_80039ACC(D_801381FC);
    if (D_8013821B >= 0) {
        D_801381E0 = D_8013821A * 18 + f * 18.0f;
    } else {
        D_801381E0 = D_8013821A * 18 - f * 18.0f;
    }
    if (D_801381FC >= 1.5707963267948966) {
        return 1;
    }
    return 0;
}
