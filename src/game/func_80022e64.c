typedef struct Camera {
    unsigned char pad0[0x18];
    float x;
    float y;
    float z;
    unsigned char pad24[0xC];
    float tx;
    float ty;
    float tz;
    unsigned char pad3C[0xC];
    float height;
    float pitch;
    float yaw;
    float roll;
} Camera;

extern float sqrtf(float value);
#pragma intrinsic(sqrtf)
extern float func_80005550(float y, float x);
extern double D_8007FB60;
extern double D_8007FB68;

void func_80022E64(Camera *cam) {
    float d[3];

    d[0] = cam->x - cam->tx;
    d[1] = cam->ty - cam->y + cam->height;
    d[2] = cam->z - cam->tz;
    cam->yaw = func_80005550(d[0], d[2]) * 180.0f / D_8007FB60;
    cam->pitch = func_80005550(d[1], sqrtf(d[0] * d[0] + d[2] * d[2])) * 180.0f / D_8007FB68;
    cam->roll = 0.0f;
}
