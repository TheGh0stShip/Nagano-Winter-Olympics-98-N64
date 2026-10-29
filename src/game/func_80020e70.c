typedef struct Body {
    unsigned char pad0[0x10];
    float vx;
    float vy;
    float vz;
    unsigned char pad1C[0x3C];
    float speed;
} Body;

extern float sqrtf(float value);
#pragma intrinsic(sqrtf)
extern double D_8007FA00;

float func_80020E70(Body *body, int unused) {
    float x, y, z;
    float sum;
    x = body->vx;
    y = body->vy;
    z = body->vz;
    sum = body->vx * x;
    sum += body->vy * y;
    sum += body->vz * z;
    return body->speed = ((sqrtf(sum) * 60.0f / 100.0f) * 3600.0f / 1000.0f) * D_8007FA00;
}
