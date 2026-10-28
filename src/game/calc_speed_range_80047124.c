extern float D_80138310[];
extern int D_80138658[];

float func_80047124(int index) {
    float a = D_80138310[index] * 0.019f + 6.0f;
    float b = a + 3.0f;
    float result = D_80138310[index] * 0.024f + b;

    if (D_80138658[index] == 2 || D_80138658[index] == 4) {
        if (6.0f < D_80138310[index] / 25.0f) {
            result /= 1.4f;
        }
    }
    return result;
}
