typedef struct { float x, y, z; } Vec;
typedef struct { char pad[0x10]; float x; float y; float z; } Obj;
typedef struct { char pad[0x28]; float a; float b; } Cam;
extern float sqrtf(float);
#pragma intrinsic(sqrtf)
extern float func_80005550(float, float);
extern float func_80025FD0(float);
extern void func_8004E7E0(float *, float, float, float, float);
extern void func_80059410(float *, float, float, float, float *, float *, float *);
extern Vec D_80071580;
extern Vec D_8007158C;
extern double D_8007FCF8;
extern double D_8007FD00;

void func_800262A0(Obj *obj, Cam *cam, float *out, int mode) {
    float m[16];
    Vec v1;
    Vec v2;
    float xx;
    float zz;
    char pad[0x10];
    Vec v3;
    Vec v4;
    float ang2;
    float ang1;
    float ang0;
    float d;

    func_8004E7E0(m, cam->a, 1.0f, 0.0f, 0.0f);
    func_80059410(m, D_80071580.x, D_80071580.y, D_80071580.z, &v1.x, &v1.y, &v1.z);
    func_80059410(m, D_8007158C.x, D_8007158C.y, D_8007158C.z, &v2.x, &v2.y, &v2.z);
    func_8004E7E0(m, cam->b, 0.0f, 1.0f, 0.0f);
    func_80059410(m, v1.x, v1.y, v1.z, &v3.x, &v3.y, &v3.z);
    func_80059410(m, v2.x, v2.y, v2.z, &v4.x, &v4.y, &v4.z);
    ang0 = func_80005550(v3.y, sqrtf(v3.x * v3.x + v3.z * v3.z));
    ang0 = ang0 * 180.0f / 3.141592653589793;
    ang1 = func_80005550(v3.x, v3.z);
    ang1 = ang1 * 180.0f / 3.141592653589793;
    ang0 = func_80025FD0(ang0);
    ang1 = func_80025FD0(ang1);
    func_80025FD0(ang2);
    out[0] = ang1 / 360.0f * 512.0f;
    out[1] = ang0 / 360.0f * 352.0f;
    out[2] = 0.0f;
    if (mode == 2 || mode == 3) {
        xx = obj->x * obj->x;
        zz = obj->z * obj->z;
        d = sqrtf(xx + zz);
        if (mode == 2) {
            out[0] += d * 512.0f / 180.0f;
        } else {
            out[0] -= d * 512.0f / 180.0f;
        }
    }
}
