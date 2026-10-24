extern double D_80080798;
extern float D_80138204;
extern float D_80138208;
extern unsigned char D_801380B8;
extern float func_80039ACC(float value);

float func_8003CECC(void) {
    float input;
    float result;

    D_80138204 = (double)D_80138204 + D_80080798;
    input = func_80039ACC(D_80138204);
    result = 1.0f - input;
    D_80138208 = -320.0f * result;
    if (input >= 1.0f) {
        D_801380B8 = 1;
    }
    return result;
}
