typedef struct Object2F1C0 {
    unsigned char pad[4];
    float x;
    float y;
    float z;
    unsigned char pad10[0x18];
    float pitch;
    float yaw;
    float roll;
} Object2F1C0;

extern unsigned char *D_80126BF0;
extern float D_80137538[];
extern float func_80005550(float a, float b);
extern float sqrtf(float value);
#pragma intrinsic(sqrtf)

void func_8002F1C0(void) {
    Object2F1C0 *object = (Object2F1C0 *)(D_80126BF0 + 0x7FB28);
    float dx = object->x - D_80137538[3];
    float dy = D_80137538[4] - object->y;
    float dz = object->z - D_80137538[5];
    float horizontal;

    object->yaw = (double)(func_80005550(dx, dz) * 180.0f) / 3.141592653589793;
    horizontal = sqrtf(dx * dx + dz * dz);
    object->pitch = (double)(func_80005550(dy, horizontal) * 180.0f) / 3.141592653589793;
    object->roll = 0.0f;
}
