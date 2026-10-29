typedef struct ViewRecord {
    unsigned char pad0[0x28];
    float yaw;
    float pitch;
    float roll;
} ViewRecord;

typedef struct TargetRecord {
    unsigned char pad0[0xC];
    float x;
    float y;
    float z;
    unsigned char pad18[0x80];
} TargetRecord;

extern unsigned char *D_80126BF0;
extern short D_80137728;
extern TargetRecord D_80137730[];
extern float sqrtf(float);
#pragma intrinsic(sqrtf)
extern float func_8004E9D0(float);
extern float func_8005C4E0(float);
extern float func_80005550(float, float);

short func_80036394(short index) {
    ViewRecord *view;
    float fy;
    float fz;
    float fx;
    float ang;
    float len;
    short result;
    int pad;

    result = 0;
    view = (ViewRecord *)(D_80126BF0 + 0x7FB28 + D_80137728 * 0x78);
    fx = -func_8005C4E0(view->yaw * 3.141592653589793 / 180.0) * func_8004E9D0(view->pitch * 3.141592653589793 / 180.0);
    fy = func_8004E9D0(view->yaw * 3.141592653589793 / 180.0);
    fz = -func_8005C4E0(view->yaw * 3.141592653589793 / 180.0) * func_8005C4E0(view->pitch * 3.141592653589793 / 180.0);
    ang = func_80005550(fy, fx) * 180.0f / 3.141592653589793;
    len = sqrtf(fx * fx + fy * fy);
    fx = func_8005C4E0((view->roll + ang) * 3.141592653589793 / 180.0) * len;
    if (D_80137730[index].x * fx + D_80137730[index].y * (func_8004E9D0((view->roll + ang) * 3.141592653589793 / 180.0) * len) + D_80137730[index].z * fz > 0.0f) {
        result = 1;
    }
    return result;
}
