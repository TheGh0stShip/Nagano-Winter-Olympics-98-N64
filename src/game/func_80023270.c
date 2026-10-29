typedef struct Falloff {
    float near;
    float pad4[2];
    float strength;
    float pad10[2];
} Falloff;

extern unsigned char D_80136C9C;
extern unsigned char D_80136C9D;
extern float D_8019D4D0[][6];

extern float sqrtf(float value);
#pragma intrinsic(sqrtf)

float func_80023270(float *v) {
    float sum;
    float near;
    float strength;
    float dist;
    float *entry;
    unsigned char i;

    sum = 0.0f;
    entry = &D_8019D4D0[D_80136C9C][D_80136C9D];
    near = entry[0];
    strength = entry[3];
    for (i = 0; i < 3; i++) {
        sum += v[i] * v[i];
    }
    dist = sqrtf(sum);
    if (dist < near) {
        sum = 1.0f - strength / near * dist;
    } else {
        sum = 1.0 - (strength + 0.001 * dist);
        if (sum < 0.0f) {
            sum = 0.0001f;
        }
    }
    return sum;
}
