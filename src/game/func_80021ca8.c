typedef struct Camera {
    unsigned char pad0[8];
    float angle;
    float x;
    float y;
    float z;
    float ex;
    float ey;
    float ez;
    unsigned char pad24[0xC];
    float tx;
    float ty;
    float tz;
} Camera;

extern float func_8004E9D0(float angle);
extern float func_8005C4E0(float angle);
extern void func_80022E64(Camera *cam);

void func_80021CA8(Camera *cam) {
    float dx;
    float pad1;
    float dz;
    float pad2[2];
    float rz;
    float pad3[3];
    float c;
    float rx;
    dx = cam->x - cam->tx;
    dz = cam->z - cam->tz;
    c = func_8005C4E0(cam->angle * 3.141592653589793 / 180.0);
    rz = c * dz - dx * func_8004E9D0(cam->angle * 3.141592653589793 / 180.0);
    c = func_8004E9D0(cam->angle * 3.141592653589793 / 180.0);
    rx = c * dz + dx * func_8005C4E0(cam->angle * 3.141592653589793 / 180.0);
    cam->ex = cam->tx + rx;
    cam->ez = cam->tz + rz;
    cam->ey = cam->y;
    func_80022E64(cam);
}
