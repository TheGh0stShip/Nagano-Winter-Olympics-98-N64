typedef struct Obj { float pad0; float x; float y; float z; } Obj;
extern float D_80136710;
float sqrtf(float);
#pragma intrinsic(sqrtf)

float func_8001F0CC(Obj *obj, float x, float y, float z) {
    float dx, dy, dz; int f;
    dx = x - obj->x;
    f = 0; if (dx < 0.0f) { f = 1; if (dx < 0.0f) dx = -dx; }
    f++;
    dy = y - obj->y;
    if (dy < 0.0f && dy < 0.0f) dy = -dy;
    dz = z - (&obj->z)[f * 0];
    if (dz < 0.0f && dz < 0.0f) dz = -dz;
    D_80136710 = sqrtf(dx * dx + dy * dy + dz * dz);
    return D_80136710;
}
