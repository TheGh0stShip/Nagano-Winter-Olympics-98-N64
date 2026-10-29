typedef struct Obj {
    unsigned char kind;
    char pad1;
    short target;
    float angle;
    char pad8[0x10];
    float ofs[3];
    char pad24[0xC];
    float base[3];
    float rx;
    float ry;
    float rz;
    float pad48;
    float rot[3];
    unsigned char fast;
    char pad59[3];
    float pos[3];
} Obj;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern Vec3 D_80070884[];
extern unsigned char D_80136C9D;

extern float func_80022F44(float, float, unsigned char);
extern void func_80024114(float *, float *, float *);
extern void func_8004E7E0(void *, float, float, float, float);
extern void func_80059410(void *, float, float, float, float *, float *, float *);

void func_80021FFC(Obj *arg0) {
    float top[3];
    float mtx[16];
    float e[3];
    float n[3];
    float c[3];
    float r[3];
    float a[3];
    Vec3 b;
    Vec3 f;
    float out[9];
    float pad[19];
    float v[3];
    float u[3];
    float h[3];
    float g[3];
    float n0;
    float neg;
    unsigned short i;
    unsigned char speed;
    float k0;
    float k1;
    float k2;

    k0 = D_80070884[D_80136C9D].x;
    k1 = D_80070884[D_80136C9D].y;
    k2 = D_80070884[D_80136C9D].z;
    func_8004E7E0(mtx, arg0->rx, 1.0f, 0.0f, 0.0f);
    func_80059410(mtx, 0.0f, 0.0f, k0, &v[0], &v[1], &v[2]);
    func_80059410(mtx, 1.0f, 0.0f, 0.0f, &u[0], &u[1], &u[2]);
    func_8004E7E0(mtx, arg0->ry, 0.0f, 1.0f, 0.0f);
    func_80059410(mtx, v[0], v[1], v[2], &h[0], &h[1], &h[2]);
    func_80059410(mtx, u[0], u[1], u[2], &g[0], &g[1], &g[2]);
    func_8004E7E0(mtx, arg0->rz, 0.0f, 0.0f, 1.0f);
    func_80059410(mtx, h[0], h[1], h[2], &a[0], &a[1], &a[2]);
    func_80059410(mtx, g[0], g[1], g[2], &b.x, &b.y, &b.z);
    func_8004E7E0(mtx, k1, b.x, b.y, b.z);
    func_80059410(mtx, a[0], a[1], a[2], &c[0], &c[1], &c[2]);
    v[0] = (c[0] - arg0->pos[0]) * 0.1;
    v[1] = (c[1] - arg0->pos[1]) * 0.1;
    v[2] = (c[2] - arg0->pos[2]) * 0.1;
    for (i = 0; i < 3; i++) {
        v[i] += arg0->pos[i];
        arg0->pos[i] = v[i];
    }
    arg0->ofs[0] = arg0->base[0] - v[0];
    arg0->ofs[1] = arg0->base[1] - v[1];
    arg0->ofs[2] = arg0->base[2] - v[2];
    arg0->angle += (float)arg0->target - arg0->angle;
    func_8004E7E0(mtx, k2, b.x, b.y, b.z);
    func_80059410(mtx, c[0], c[1], c[2], &f.x, &f.y, &f.z);
    neg = -1.0f;
    if (1) {
    e[0] = neg * f.x;
    e[1] = neg * f.y;
    e[2] = neg * f.z;
    }
    n0 = neg * b.x;
    n[1] = neg * b.y;
    n[2] = neg * b.z;
    func_8004E7E0(mtx, arg0->angle * neg, e[0], e[1], e[2]);
    func_80059410(mtx, n0, n[1], n[2], &r[0], &r[1], &r[2]);
    func_80024114(r, e, out);
    speed = 2;
    if (arg0->fast) {
        speed = 0xF0;
    }
    switch (arg0->kind) {
    case 3:
        arg0->rot[0] += func_80022F44(out[0], arg0->rot[0], speed);
        arg0->rot[1] += func_80022F44(out[1], arg0->rot[1], speed);
        arg0->rot[2] += func_80022F44(out[2], arg0->rot[2], speed);
        break;
    case 4:
        arg0->rot[0] = out[0];
        arg0->rot[1] = out[1];
        arg0->rot[2] = out[2];
        break;
    }
}

