extern float sqrtf(float);
#pragma intrinsic (sqrtf)

void func_800214D0(float *in, float *out) {
    unsigned char i;
    unsigned char zeros;
    float min;
    float a;
    float len;
    float d;

    min = 0.0f;
    for (i = 0; i < 3; i++) {
        if ((int)in[i] != 0) {
            if (in[i] < 0.0f) {
                min = -in[i];
            } else {
                min = in[i];
            }
            break;
        }
    }
    if (min == 0.0f) {
        min = 1.0f;
    }
    for (i = 0; i < 3; i++) {
        if (in[i] < 0.0f) {
            a = -in[i];
        } else {
            a = in[i];
        }
        if (a < min) {
            int k = (int)in[i];
            int ak;
            if (k < 0) {
                ak = -k;
            } else {
                ak = k;
            }
            if (ak != 0) {
                if (in[i] < 0.0f) {
                    min = -in[i];
                } else {
                    min = in[i];
                }
            }
        }
    }
    zeros = 0;
    for (i = 0; i < 3; i++) {
        if ((int)in[i] == 0) {
            zeros++;
        }
    }
    len = 0.0f;
    switch (zeros) {
    case 0:
    case 1:
        for (i = 0; i < 3; i++) {
            out[i] = in[i] / min;
            len += out[i] * out[i];
        }
        i = 0;
        for (; i < 3; i++) {
            out[i] /= sqrtf(len);
        }
        break;
    case 2:
        for (i = 0; i < 3; i++) {
            if (in[i] != 0.0f) {
                if (in[i] > 0.0f) {
                    out[i] = 1.0f;
                } else {
                    out[i] = -1.0f;
                }
            } else {
                out[i] = 0.0f;
            }
        }
        break;
    case 3:
    default:
        for (i = 0; i < 3; i++) {
            out[i] = 0.0f;
        }
        break;
    }
}
