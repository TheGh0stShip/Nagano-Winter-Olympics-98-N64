extern unsigned char D_80136C9D;
extern float D_8007FC08;
extern float D_8007FC0C;

void func_80023AB0(float *values) {
    float base = 1.0f;
    float scale = base;
    double factor;
    unsigned short i;

    switch (D_80136C9D) {
        case 1:
            scale = base * 0.8f;
            break;
        case 2:
            scale = base * 0.7f;
            break;
    }
    factor = scale;
    scale = factor;
    for (i = 0; i < 3; i++) {
        values[i] *= scale;
    }
}
