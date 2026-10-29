typedef struct Selector {
    unsigned char pad0[0x32];
    unsigned char index;
} Selector;

typedef struct Direction {
    unsigned char pad0[0x10];
    float x;
    unsigned char pad14[4];
    float z;
} Direction;

extern signed char D_80070CB8[];
extern void func_80021328(float angle, float *vector);
extern void func_80021758(float scale, float *out, float *in);
extern float sqrtf(float value);
#pragma intrinsic(sqrtf)

void func_80024F4C(int unused, float *vector, Selector *selector, Direction *direction) {
    float output[4];
    float angle;
    float length;
    float sum;

    if (D_80070CB8[selector->index] == 1) {
        angle = 110.0f;
    } else {
        angle = 70.0f;
    }
    if (selector->index == 2) {
        angle = -70.0f;
    }
    func_80021328(angle, vector);
    sum = direction->x * direction->x;
    sum += direction->z * direction->z;
    length = sqrtf(sum);
    vector[1] = 0.0f;
    func_80021758(length, output, vector);
    direction->x = output[0];
    direction->z = output[2];
}
