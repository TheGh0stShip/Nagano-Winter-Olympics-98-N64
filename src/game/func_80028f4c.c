extern unsigned char *D_80126BF0;
extern unsigned char D_801374B2;
extern float D_801372E0[];
extern unsigned int func_80046280(unsigned char mode, float time);
extern unsigned char func_8002B4B4(float time);
extern float func_80029198(float time);

float func_80028F4C(float time) {
    unsigned char slot;
    float sum;
    float t;
    float base;

    if (D_801374B2 != 11) {
        return time;
    }
    base = func_80046280(D_80126BF0[0x977EC], time);
    if (time == -1.0f) {
        return 0.0f;
    }
    slot = func_8002B4B4(time);
    sum = D_801372E0[slot] + base;
    if (D_80126BF0[0x977EC] != 0) {
        t = sum;
    } else {
        t = func_80029198(sum);
    }
    if (t == -1.0f) {
        return 0.0f;
    }
    if (t < D_801372E0[slot]) {
        return 0.0f;
    }
    return t - D_801372E0[slot];
}
