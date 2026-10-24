extern float func_80059400(float value);

void func_8005B980(float *x, float *y, float *z) {
    float inverse = 1.0f /
        func_80059400(*x * *x + *y * *y + *z * *z);

    *x *= inverse;
    *y *= inverse;
    *z *= inverse;
}
