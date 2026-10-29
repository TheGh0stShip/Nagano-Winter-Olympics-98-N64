extern float sqrtf(float);
#pragma intrinsic(sqrtf)
extern double fabs(double);
#pragma intrinsic(fabs)
extern float func_80005550(float, float);
extern float func_8004E9D0(float);
extern float func_8005C4E0(float);
extern double D_80080BD0;
extern double D_80080BD8;
typedef struct { float x; float y; float z; } Vec3f;

void func_80043908(float rx, float ry, Vec3f *out) {
    float x;
    float c1;
    float w;
    float p;
    float y;
    float s1;
    float a;
    float z;
    float q;
    float b;
    double ad;
    float r;

    a = -rx * 3.141592653589793 / 180.0;
    s1 = -func_8004E9D0(a);
    c1 = -func_8005C4E0(a);
    b = ry * 3.141592653589793 / 180.0;
    x = func_8005C4E0(b) * c1;
    y = func_8004E9D0(b);
    z = func_8005C4E0(b) * -s1;
    out->z = func_80005550(y, x) * 180.0f / 3.141592653589793;
    out->y = func_80005550(z, sqrtf(x * x + y * y)) * 180.0f / 3.141592653589793;
    ad = fabs(s1);
    p = func_8005C4E0(func_80005550(0.0f, s1) - out->z * 3.141592653589793 / 180.0) * ad;
    ad = fabs(s1);
    q = func_8004E9D0(func_80005550(0.0f, s1) - out->z * 3.141592653589793 / 180.0) * ad;
    w = sqrtf(p * p + c1 * c1);
    w = func_8005C4E0(func_80005550(c1, p) - out->y * 3.141592653589793 / 180.0) * w;
    r = sqrtf(p * p + c1 * c1);
    out->x = func_80005550(q, func_8004E9D0(func_80005550(c1, p) - out->y * 3.141592653589793 / 180.0) * r) * 180.0f / 3.141592653589793;
}
