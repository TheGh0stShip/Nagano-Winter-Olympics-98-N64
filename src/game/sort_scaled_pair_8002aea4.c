extern signed char D_80071A50[];
void func_8002AEA4(float *values, unsigned char kind) {
    unsigned char i;
    unsigned char j;
    float a;
    float b;
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            a = values[j] * D_80071A50[kind];
            b = values[j + 1] * D_80071A50[kind];
            if (b < a) {
                a = values[j];
                values[j] = values[j + 1];
                values[j + 1] = a;
            }
        }
    }
}
