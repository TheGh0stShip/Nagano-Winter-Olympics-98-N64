typedef struct Aim {
    unsigned char pad0[4];
    float x;
    float y;
    float z;
    unsigned char pad10[0x18];
    float pitch;
    float yaw;
    float zero;
} Aim;

extern double D_80138570;
extern float func_80005550(float y, float x);
extern float sqrtf(float value);
#pragma intrinsic(sqrtf)

void func_80046AB0(Aim *aim, float x, float y, float z) {
    float dx = x - aim->x;
    float dz = y - aim->y;
    float dy = z - aim->z;

    aim->zero = 0.0f;
    aim->yaw = func_80005550(-dx, -dy) * 360.0f / (2.0f + 0) / D_80138570;
    aim->pitch = func_80005550(dz, sqrtf(dx * dx + dy * dy)) * 360.0f / (2.0f + 0) / D_80138570;
}
