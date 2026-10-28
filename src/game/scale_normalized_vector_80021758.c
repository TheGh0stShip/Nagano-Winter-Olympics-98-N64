extern float sqrtf(float value);
#pragma intrinsic(sqrtf)

void func_80021758(float scale, float *out, float *in) {
    float sum = 0.0f;
    float length;
    unsigned char i;

    for (i = 0; i < 3; i++) {
        sum += in[i] * in[i];
    }
    length = sqrtf(sum);
    if (length != 0.0f) {
        for (i = 0; i < 3; i++) {
            out[i] = in[i] * scale / length;
        }
    } else {
        for (i = 0; i < 3; i++) {
            out[i] = 0.0f;
        }
    }
}
