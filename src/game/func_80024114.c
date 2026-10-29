extern float func_80005550(float y, float x);
extern float func_8004E9D0(float angle);
extern float func_8005C4E0(float angle);
extern double D_8007FC60;

void func_80024114(float *dir, float *up, float *out) {
    float pad;
    float a;
    float b;
    float pad2;
    float c;
    float s;
    float t;
    float x;
    double d;

    c = func_8005C4E0(out[2] = func_80005550(dir[1], dir[0]));
    s = func_8004E9D0(out[2]);
    x = dir[1] * s + dir[0] * c;
    a = up[1] * s + up[0] * c;
    b = up[1] * c + -up[0] * s;
    t = func_8004E9D0(out[1] = -func_80005550(dir[2], x));
    x = -func_80005550(b, a * t + up[2] * func_8005C4E0(out[1]));
    d = D_8007FC60;
    out[0] = x * d;
    out[1] = out[1] * d;
    out[2] = out[2] * d;
}
