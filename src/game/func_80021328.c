extern float func_8004E9D0(float angle);
extern float func_8005C4E0(float angle);
extern double D_8007FA18;
extern double D_8007FA20;

void func_80021328(float degrees, float *v) {
    float angle;
    float local[3];
    unsigned char i;
    float c;

    for (i = 0; i < 3; i++) {
        local[i] = v[i];
    }
    angle = degrees * D_8007FA18 / D_8007FA20;
    c = func_8005C4E0(angle);
    v[2] = c * local[2] - func_8004E9D0(angle) * local[0];
    c = func_8004E9D0(angle);
    v[0] = c * local[2] + func_8005C4E0(angle) * local[0];
}
