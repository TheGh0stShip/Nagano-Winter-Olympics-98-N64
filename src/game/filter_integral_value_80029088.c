extern unsigned char D_801374B2;
extern float func_80029198(float value);

float func_80029088(float value) {
    int whole = (int)value;

    if (whole == 0) {
        return value;
    }
    if (whole == -1) {
        return value;
    }
    if (D_801374B2 != 11) {
        return func_80029198(value);
    }
    return value;
}
