typedef struct Position2EF28 {
    unsigned char pad[4];
    float x;
    float y;
    float z;
} Position2EF28;

extern unsigned char *D_80126BF0;
extern float D_80137538[3];
extern float func_8002F2A4(float value);
extern void func_8002F1C0(void);
extern float sqrtf(float value);
#pragma intrinsic(sqrtf)

int func_8002EF28(float value) {
    Position2EF28 *position = (Position2EF28 *)(D_80126BF0 + 0x7FB28);
    int pad;
    float dx = D_80137538[0] - position->x;
    float dy = D_80137538[1] - position->y;
    float dz = D_80137538[2] - position->z;
    float distance = sqrtf(dx * dx + dy * dy + dz * dz);
    float scale;

    if (distance < 30.0f) {
        return 1;
    }
    scale = func_8002F2A4(value);
    dx *= scale;
    dy *= scale;
    dz *= scale;
    position->x += dx;
    position->y += dy;
    position->z += dz;
    func_8002F1C0();
    return 0;
}
