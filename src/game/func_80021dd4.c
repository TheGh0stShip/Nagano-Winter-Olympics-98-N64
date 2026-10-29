typedef struct Cam {
    unsigned char pad0[0x18];
    float x;
    float y;
    float z;
    float dx;
    float dy;
    float dz;
    float tx;
    float ty;
    float tz;
    unsigned char pad3C[0xC];
    float pitch;
} Cam;

extern unsigned char D_80136C9D;
extern void func_80022E64(Cam *cam);
float sqrtf(float);
#pragma intrinsic(sqrtf)

#define ABS(x) ((x) < 0.0f ? -(x) : (x))

void func_80021DD4(Cam *cam) {
    float pad[6];
    float a;
    float b;
    float c;
    float s;
    float dy;
    float dz;
    int sign;

    if (cam->dx > -1.0f && cam->dx < 0.0f) {
        cam->dx = -1.0f;
    }
    if (cam->dx >= 0.0f && cam->dx < 1.0f) {
        cam->dx = 1.0f;
    }
    a = ABS(cam->dx) / ABS(cam->dx);
    dy = cam->dy;
    b = ABS(dy) / ABS(cam->dx);
    dz = cam->dz;
    c = ABS(dz) / ABS(cam->dx);
    s = 400.0f / sqrtf(a * a + b * b + c * c);
    cam->x = cam->tx - a * s;
    cam->z = cam->tz - c * s;
    sign = (dy < 0.0f) ? -1 : 1;
    cam->y = cam->ty - sign * (b * s) + 100.0f;
    if (D_80136C9D == 1) {
        cam->pitch = -30.0f;
        cam->y += 250.0f;
    }
    func_80022E64(cam);
}
