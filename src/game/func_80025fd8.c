typedef struct Vec3 { float x; float y; float z; } Vec3;
typedef struct Obj { unsigned char pad0[0x28]; float rx; float ry; float rz; } Obj;

extern float func_80005550(float y, float x);
extern float func_80025FD0(float a);
extern void func_8004E7E0(float m[4][4], float angle, float x, float y, float z);
extern void func_80059410(float m[4][4], float x, float y, float z, float *ox, float *oy, float *oz);
extern Vec3 D_80071580;
extern Vec3 D_8007158C;
extern double D_8007FCE0;
extern double D_8007FCE8;
extern double D_8007FCF0;
float sqrtf(float);
#pragma intrinsic(sqrtf)

void func_80025FD8(int unused, Obj *obj, Vec3 *out) {
    float p0[1];
    float m[4][4];
    Vec3 a0;
    Vec3 b0;
    Vec3 a1;
    Vec3 b1;
    Vec3 a2;
    Vec3 b2;
    float roll;
    float yaw;
    float pitch;
    float p1[2];

    func_8004E7E0(m, obj->rx, 1.0f, 0.0f, 0.0f);
    func_80059410(m, D_80071580.x, D_80071580.y, D_80071580.z, &a0.x, &a0.y, &a0.z);
    func_80059410(m, D_8007158C.x, D_8007158C.y, D_8007158C.z, &b0.x, &b0.y, &b0.z);
    func_8004E7E0(m, obj->ry, 0.0f, 1.0f, 0.0f);
    func_80059410(m, a0.x, a0.y, a0.z, &a1.x, &a1.y, &a1.z);
    func_80059410(m, b0.x, b0.y, b0.z, &b1.x, &b1.y, &b1.z);
    func_8004E7E0(m, obj->rz, 0.0f, 0.0f, 1.0f);
    func_80059410(m, a1.x, a1.y, a1.z, &a2.x, &a2.y, &a2.z);
    func_80059410(m, b1.x, b1.y, b1.z, &b2.x, &b2.y, &b2.z);
    pitch = func_80005550(a2.y, sqrtf(a2.x * a2.x + a2.z * a2.z)) * 180.0f / D_8007FCE0;
    yaw = func_80005550(a2.x, a2.z) * 180.0f / D_8007FCE8;
    roll = func_80005550(b2.y, sqrtf(b2.x * b2.x + b2.z * b2.z)) * 180.0f / D_8007FCF0;
    pitch = func_80025FD0(pitch);
    yaw = func_80025FD0(yaw);
    roll = func_80025FD0(roll);
    out->x = yaw / 360.0f * 512.0f;
    out->y = pitch / 360.0f * 352.0f;
    out->z = -1.0f * roll;
}
