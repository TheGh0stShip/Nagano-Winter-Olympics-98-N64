typedef struct {
    char pad0[8];
    float f8;
    float pos[3];
    float x18, y1C, z20;
    float f24;
    float f28;
    float f2C;
    float x30, y34, z38;
    char pad3C[0x48 - 0x3C];
    float h48;
    float rx4C;
    float ry50;
    float rz54;
} Cam;
extern float sqrtf(float);
#pragma intrinsic(sqrtf)
extern float func_80005550(float, float);
extern void func_80021328(float, float *);
extern void func_800214D0(float *, float *);
extern void func_80023144(float *);

void func_80022A40(Cam *c) {
    float s;
    float p[3];
    float q[3];
    float t;
    float v[3];
    float d[3];

    p[0] = c->pos[0];
    p[1] = c->pos[1];
    p[2] = c->pos[2];
    func_800214D0(p, q);
    v[0] = c->f24;
    v[2] = c->f2C;
    v[1] = 1.0f - q[1];
    func_80021328(c->f8, v);
    t = v[0] * v[0] + v[2] * v[2];
    s = (float)(180.0 / sqrtf(t)) * 1.5;
    t = c->x30 - v[0] * s; c->x18 = t;
    t = c->z38 - v[2] * s; c->z20 = t;
    t = c->y34 + c->h48 * 0.6 + 90.0; c->y1C = t;
    d[0] = c->x30 - c->x18;
    d[1] = c->y34 - c->y1C + c->h48;
    d[2] = c->z38 - c->z20;
    t = func_80005550(d[0], d[2]) * 180.0f / 3.141592653589793 + 180.0;
    func_80023144(&c->ry50);
    c->ry50 = t;
    t = func_80005550(d[1], sqrtf(d[0] * d[0] + d[2] * d[2])) * 180.0f / 3.141592653589793;
    func_80023144(&c->rx4C);
    c->rx4C = t;
    c->rz54 = 0.0f;
}
