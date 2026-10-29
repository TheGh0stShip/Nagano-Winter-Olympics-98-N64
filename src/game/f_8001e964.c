typedef struct Angles {
    unsigned char pad0[0xC];
    float z;
    float y;
    float x;
    float yaw;
    float pitch;
} Angles;

typedef struct Camera {
    float pad0;
    float x;
    float y;
    float z;
} Camera;

extern float func_80005550(float y, float x);
extern void func_8001E830(unsigned short angle, float scale, float *first, float *second);
extern float sqrtf(float value);
#pragma intrinsic(sqrtf)

void func_8001E964(Angles *angles, Camera *camera, float scale, float x, float y, float z) {
    float dx;
    float dy;
    float dz;

    dx = x - camera->x;
    dy = y - camera->y;
    dz = z - camera->z;

    angles->yaw = func_80005550(dz, dx) * 180.0f / 3.141592654;
    angles->pitch = func_80005550(dy, sqrtf(dx * dx + dz * dz)) * 180.0f / 3.141592654;
    func_8001E830(angles->pitch + 180.0f, scale, &angles->x, &angles->y);
    func_8001E830(angles->yaw - 90.0f, scale, &angles->x, &angles->z);
}
