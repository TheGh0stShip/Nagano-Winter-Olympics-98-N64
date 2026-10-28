extern float D_80080D3C;
extern float func_80046838(float, float, float);

unsigned char func_800466E0(float value) {
    return func_80046838(value, D_80080D3C, 90000.0f);
}

extern float D_80080D40;
extern float func_80046838(float, float, float);

unsigned char func_8004678C(float value) {
    return func_80046838(value, D_80080D40, 155000.0f);
}

float func_80046838(float x, float y, float z) {
    float result = 0.0f;
    float d;
    float e;

    if (result < x) {
        if (x < y) {
            result = 250.0f - x / y * 50.0f;
        } else if (x < z) {
            d = z - y;
            e = x - y - d;
            result = 200.0f / (d * d) * e * e;
        }
    }
    return result;
}
