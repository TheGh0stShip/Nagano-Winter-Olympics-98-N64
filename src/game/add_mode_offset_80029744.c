extern unsigned char D_801374B2;
extern signed char D_80071A50[];
extern float D_800800F8;

float func_80029744(float value) {
    if (D_80071A50[D_801374B2] == 1) {
        return D_800800F8 + value;
    }
    return 0.0f;
}
