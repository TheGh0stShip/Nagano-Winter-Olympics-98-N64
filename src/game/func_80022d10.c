typedef struct Camera {
    unsigned char mode;
    unsigned char pad1[0xB];
    float rx;
    float ry;
    float rz;
    float x;
    float y;
    float z;
    unsigned char pad24[0xC];
    float tx;
    float ty;
    float tz;
    unsigned char pad3C[0xC];
    float height;
    float angle[3];
} Camera;

extern void func_8004E7E0(float mf[4][4], float a, float x, float y, float z);
extern void func_80059410(float mf[4][4], float x, float y, float z, float *ox, float *oy, float *oz);
extern void func_80024114(float *dir, float *up, float *out);
extern float func_80022F44(float target, float current, int rate);

void func_80022D10(Camera *cam) {
    long long pad;
    float m[4][4];
    float d[3];
    float o[3];
    float a[3];

    d[0] = (cam->tx - cam->x) * -1.0f;
    d[1] = (cam->ty - cam->y + cam->height) * -1.0f;
    d[2] = (cam->tz - cam->z) * -1.0f;
    func_8004E7E0(m, 90.0f, cam->rx, cam->ry, cam->rz);
    func_80059410(m, d[0], d[1], d[2], &o[0], &o[1], &o[2]);
    func_80024114(o, d, a);
    switch (cam->mode) {
    case 11:
        cam->angle[0] += func_80022F44(a[0], cam->angle[0], 2);
        cam->angle[1] += func_80022F44(a[1], cam->angle[1], 2);
        cam->angle[2] += func_80022F44(a[2], cam->angle[2], 2);
        break;
    case 12:
        cam->angle[0] = a[0];
        cam->angle[1] = a[1];
        cam->angle[2] = a[2];
        break;
    }
}
