typedef struct Angles {
    unsigned char pad0[0x18];
    float yaw;
    float pitch;
} Angles;

typedef struct Camera {
    float pad0;
    float x;
    float y;
    float z;
    unsigned char pad10[0x18];
    float rot_x;
    float rot_y;
    float rot_z;
} Camera;

extern float func_80005550(float y, float x);
extern float sqrtf(float value);
#pragma intrinsic(sqrtf)

void func_8001EB74(Angles *angles, Camera *camera, float x, float y, float z) {
    float dx;
    float dy;
    float dz;

    dx = x - camera->x;
    dy = y - camera->y;
    dz = z - camera->z;

    angles->yaw = func_80005550(dz, dx) * 180.0f / 3.141592654;
    angles->pitch = func_80005550(dy, sqrtf(dx * dx + dz * dz)) * 180.0f / 3.141592654;
    camera->rot_x = angles->pitch;
    camera->rot_y = 270.0f - angles->yaw;
    camera->rot_z = 0.0f;
}
