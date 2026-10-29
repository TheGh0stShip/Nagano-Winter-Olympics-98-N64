typedef struct Cam {
    unsigned char mode;
    unsigned char pad1;
    short roll;
    unsigned char pad4[8];
    float pos[3];
    float eye[3];
    float dir[3];
    float at[3];
    float pad3C[3];
    float height;
    float pitch;
    float yaw;
    float spin;
} Cam;

typedef struct Res { float a; float b; float c; } Res;


extern float sqrtf(float);
#pragma intrinsic(sqrtf)
extern float func_80005550(float, float);
extern void func_800214D0(float *, Res *);
extern float func_80022F44(float, float, unsigned char);
extern void func_80023144(float *);
extern float func_8005C4E0(float, float);

void func_80022494(Cam *cam) {

    float v[3];
    float d[3];
    float k;
    float ang;
    Res res;
    float delta[3];

    v[0] = cam->pos[0];
    v[1] = cam->pos[1];
    v[2] = cam->pos[2];
    func_800214D0(v, &res);
    d[0] = cam->dir[0];
    d[2] = cam->dir[2];
    d[1] = 1.0f - res.b;
    ang = d[0] * d[0] + d[2] * d[2];
    k = sqrtf(ang);
    switch (cam->mode) {
    case 8:
        k = 180.0 / k;
        ang = cam->at[0] + d[0] * k * 0.1;
        cam->eye[0] = ang;
        ang = cam->at[2] + d[2] * k * 0.1;
        cam->eye[2] = ang;
        cam->eye[1] = cam->at[1] + cam->height * 0.6;
        break;
    case 4:
        k = 180.0 / k;
        ang = cam->at[0] - d[0] * k;
        cam->eye[0] = ang;
        ang = cam->at[2] - d[2] * k;
        cam->eye[2] = ang;
        cam->eye[1] = (cam->at[1] + cam->height * 0.6) + d[1] * k * 0.6 + 60.0;
        break;
    case 3:
    default:
        ang = (cam->at[0] - d[0] * (float)(180.0 / k)) - cam->eye[0];
        ang = ang * 0.1;
        cam->eye[0] = cam->eye[0] + ang;
        ang = (cam->at[2] - d[2] * (float)(180.0 / k)) - cam->eye[2];
        ang = ang * 0.1;
        cam->eye[2] = cam->eye[2] + ang;
        ang = d[1] * (float)(180.0 / k) * 0.6 * 6.0 + (cam->at[1] + cam->height * 0.6) + 60.0 - cam->eye[1];
        ang = ang * 0.1;
        cam->eye[1] = cam->eye[1] + ang;
        break;
    }
    delta[0] = cam->at[0] - cam->eye[0];
    delta[1] = (cam->at[1] - cam->eye[1]) + cam->height;
    delta[2] = cam->at[2] - cam->eye[2];
    switch (cam->mode) {
    case 8:
        ang = func_80005550(delta[0], delta[2]) * 180.0f / 3.141592653589793;
        func_80023144(&cam->yaw);
        cam->yaw += func_80022F44(ang, cam->yaw, 1);
        ang = d[1] * 120.0f;
        ang = (360.0f - ang) - 10.0f;
        func_80023144(&cam->pitch);
        cam->pitch += func_80022F44(ang, cam->pitch, 8);
        ang = func_8005C4E0((float)((float)(func_80005550(delta[0], delta[2]) * 180.0f / 3.141592653589793) - 180.0f) * 3.141592653589793 / 180.0, 180.0f) * (float)(cam->roll * 2);
        func_80023144(&cam->spin);
        cam->spin += func_80022F44(ang, cam->spin, 2);
        break;
    case 4:
        ang = func_80005550(delta[0], delta[2]) * 180.0f / 3.141592653589793 + 180.0;
        func_80023144(&cam->yaw);
        cam->yaw = ang;
        ang = func_80005550(delta[1], sqrtf(delta[0] * delta[0] + delta[2] * delta[2])) * 180.0f / 3.141592653589793;
        func_80023144(&cam->pitch);
        cam->pitch = ang;
        cam->spin = 0.0f;
        break;
    case 3:
    default:
        ang = func_80005550(delta[0], delta[2]) * 180.0f / 3.141592653589793 + 180.0;
        func_80023144(&cam->yaw);
        cam->yaw += func_80022F44(ang, cam->yaw, 1);
        ang = func_80005550(delta[1], sqrtf(delta[0] * delta[0] + delta[2] * delta[2])) * 180.0f / 3.141592653589793;
        func_80023144(&cam->pitch);
        cam->pitch += func_80022F44(ang, cam->pitch, 1);
        cam->spin = 0.0f;
        break;
    }
}
