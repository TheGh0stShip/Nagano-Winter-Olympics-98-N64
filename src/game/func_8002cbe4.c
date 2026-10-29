extern double D_80080130;
extern unsigned char D_801374E8[];

void func_8002CBE4(float value, unsigned char index) {
    float a;

    if (value < 0.0f) {
        a = -value;
    } else {
        a = value;
    }
    D_801374E8[index] = 255 - (unsigned char)(a * D_80080130);
}
