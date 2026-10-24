extern double D_80080790;
extern float D_80138204;
extern float D_80138208;
extern float func_80039ACC(float value);

float func_8003CE68(void) {
    float result;

    D_80138204 = (double)D_80138204 - D_80080790;
    result = 1.0f - func_80039ACC(D_80138204);
    D_80138208 = -320.0f * result;
    return result;
}
