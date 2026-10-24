extern float func_8004E9D0(float value);

float func_80039ACC(float value) {
    if (value < 0.0f) {
        value = 0.0f;
    }
    if (1.5707963267948966 < (double)value) {
        value = 1.5707963705062866f;
    }
    return func_8004E9D0(value);
}
