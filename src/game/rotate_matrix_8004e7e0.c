extern void func_8005B980(float *x, float *y, float *z);
extern float func_8004E9D0(float angle);
extern float func_8005C4E0(float angle);
extern void func_80052940(float mf[4][4]);
extern void func_80052840(float mf[4][4], void *m);
extern float D_80191980;

void func_8004E7E0(float mf[4][4], float a, float x, float y, float z) { float sine, cosine, ab, bc, ca, t; D_80191980 = 3.1415926 / 180.0;
    func_8005B980(&x, &y, &z);
    a *= D_80191980;
    sine = func_8004E9D0(a);
    cosine = func_8005C4E0(a);
    t = 1 - cosine;
    ab = x * y * t;
    bc = y * z * t;
    ca = z * x * t;

    func_80052940(mf);

    t = x * x;
    mf[0][0] = t + cosine * (1 - t);
    mf[2][1] = bc - x * sine;
    mf[1][2] = bc + x * sine;

    t = y * y;
    mf[1][1] = t + cosine * (1 - t);
    mf[2][0] = ca + y * sine;
    mf[0][2] = ca - y * sine;

    t = z * z;
    mf[2][2] = t + cosine * (1 - t);
    mf[1][0] = ab - z * sine;
    mf[0][1] = ab + z * sine;
}

void func_8004E974(void *m, float a, float x, float y, float z) {
    float mf[4][4];

    func_8004E7E0(mf, a, x, y, z);
    func_80052840(mf, m);
}
