double fabs(double);
#pragma intrinsic (fabs)

typedef struct DebugCamera {
    unsigned char pad0[0x4];
    float x;
    float y;
    float z;
    unsigned char pad10[0x18];
    float pitch;
    float yaw;
    unsigned char pad30[0x48];
} DebugCamera;

extern unsigned char *D_80126BF0;
extern unsigned short func_80005CAC(void);
extern void func_80005C48(void);
extern float func_8004E9D0(float angle);
extern float func_8005C4E0(float angle);

void func_80004B9C(short index) {
    short p4;
    unsigned short buttons;
    unsigned short speed;
    unsigned short rise;
    short strafe;
    short forward;
    DebugCamera *cam;
    int p0, p1, p2, p3;

    rise = speed = 1;
    buttons = func_80005CAC();
    func_80005C48();
    cam = &((DebugCamera *)(D_80126BF0 + 0x7FB28))[index];
    if (buttons & 0x2000) {
        speed = 100;
        rise = 100;
    }
    strafe = (*(short *)(D_80126BF0 + 0x7C8FA) + *(short *)(D_80126BF0 + 0x7C908) + *(short *)(D_80126BF0 + 0x7C916) + *(short *)(D_80126BF0 + 0x7C924)) * speed / 8;
    forward = (*(short *)(D_80126BF0 + 0x7C8FC) + *(short *)(D_80126BF0 + 0x7C90A) + *(short *)(D_80126BF0 + 0x7C918) + *(short *)(D_80126BF0 + 0x7C926)) * speed / 8;
    if (buttons & 0x20) {
        cam->y -= rise;
    }
    if (buttons & 0x10) {
        cam->y += speed;
    }
    if (forward >= 0) {
        cam->x += (float)(fabs(forward) * func_8004E9D0((cam->yaw + 180.0) * 3.141592653589793 / 180.0));
        cam->z += (float)(fabs(forward) * func_8005C4E0((cam->yaw + 180.0) * 3.141592653589793 / 180.0));
    }
    if (forward < 0) {
        cam->x += (float)(fabs(forward) * func_8004E9D0(cam->yaw * 3.141592653589793 / 180.0));
        cam->z += (float)(fabs(forward) * func_8005C4E0(cam->yaw * 3.141592653589793 / 180.0));
    }
    if (strafe >= 0) {
        cam->x += (float)(fabs(strafe) * func_8004E9D0((cam->yaw + 90.0) * 3.141592653589793 / 180.0));
        cam->z += (float)(fabs(strafe) * func_8005C4E0((cam->yaw + 90.0) * 3.141592653589793 / 180.0));
    }
    if (strafe < 0) {
        cam->x += (float)(fabs(strafe) * func_8004E9D0((cam->yaw - 90.0) * 3.141592653589793 / 180.0));
        cam->z += (float)(fabs(strafe) * func_8005C4E0((cam->yaw - 90.0) * 3.141592653589793 / 180.0));
    }
    if (buttons & 2) {
        cam->yaw += speed;
    }
    if (buttons & 1) {
        cam->yaw -= speed;
    }
    if (buttons & 8) {
        cam->pitch -= speed;
    }
    if (buttons & 4) {
        cam->pitch += speed;
    }
}
