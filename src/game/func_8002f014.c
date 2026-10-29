typedef struct Vec3f { float x, y, z; } Vec3f;
typedef struct Body { float pad0; float x; float y; float z; } Body;

extern void func_8002F1C0(void);
extern float func_8002F2A4(void);
extern float func_8002F2AC(float);
extern float func_8004E9D0(float);
extern float func_8005C4E0(float);
extern float sqrtf(float);
#pragma intrinsic(sqrtf)
extern double D_80080200;
extern double D_80080208;
extern double D_80080210;
extern double D_80080218;
extern float D_80080220;
extern char *D_80126BF0;
extern Vec3f D_80137538;
extern unsigned short D_80137556;

int func_8002F014(void) {
    Body *b;
    float angle;
    float pad[4];
    float dx;
    float nz;
    float dz;
    float nx;
    float c;
    float a;
    float t;
    int r;

    b = (Body *)(D_80126BF0 + 0x7FB28);
    angle = func_8002F2A4();
    dx = b->x - D_80137538.x;
    dz = b->z - D_80137538.z;
    c = func_8005C4E0((float)(angle * D_80080200 / D_80080208));
    a = (float)(angle * D_80080210 / D_80080218);
    nz = c * dz - func_8004E9D0(a) * dx;
    c = func_8004E9D0(a);
    nx = func_8005C4E0(a) * dx + c * dz;
    if (sqrtf(dx * dx + dz * dz) > 300.0f) {
        nx *= D_80080220;
        nz *= D_80080220;
    }
    b->x = D_80137538.x + nx;
    b->z = D_80137538.z + nz;
    func_8002F1C0();
    t = func_8002F2AC(480.0f);
    if (t < (float)(unsigned int)D_80137556) {
        return 1;
    }
    return 0;
}
