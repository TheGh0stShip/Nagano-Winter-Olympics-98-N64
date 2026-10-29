typedef struct {
    char pad0[8];
    float dist;
    float x;
    float y;
    float z;
    float ex;
    float ey;
    float ez;
    float tx;
    float ty;
    float tz;
    char pad30[0x28];
    unsigned char done;
} C80021918;
extern float sqrtf(float);
#pragma intrinsic(sqrtf)
extern void func_80022E64(C80021918 *);

#define ABSF(v) ((v) < 0.0f ? -(v) : (v))

void func_80021918(C80021918 *cam) {
    float pad[6];
    float dx, dy, dz;
    float r0, r1, r2;
    float s;
    float ax, ay;
    float x;
    float dist;

    x = cam->x;
    dx = cam->tx - x;
    dy = cam->ty - cam->y;
    dz = cam->tz - cam->z;
    if (sqrtf(dx * dx + dy * dy + dz * dz) < (dist = cam->dist)) {
        cam->done = 1;
        return;
    }
    if (dx == 0.0f) dx = 1.0f;
    r0 = ABSF(dx) / ABSF(dx);
    r1 = ABSF(dy) / ABSF(dx);
    r2 = ABSF(dz) / ABSF(dx);
    s = dist / sqrtf(r0 * r0 + r1 * r1 + r2 * r2);
    r0 *= s;
    r1 *= s;
    if (dx > 0.0f) cam->ex = x + r0; else cam->ex = x - r0;
    if (dy > 0.0f) cam->ey = cam->y + r1; else cam->ey = cam->y - r1;
    if (dz > 0.0f) cam->ez = cam->z + r2 * s; else cam->ez = cam->z - r2 * s;
    func_80022E64(cam);
}
