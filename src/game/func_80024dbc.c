typedef struct Obj {
    unsigned char pad0[0x10];
    float x;
    float y;
    float z;
    unsigned char pad1c[0x16];
    unsigned char kind;
} Obj;

typedef struct Out3 {
    float pad0;
    float x;
    float y;
    float z;
} Out3;

typedef struct Out4 {
    unsigned char pad0[0x14];
    float x;
    float y;
    float z;
} Out4;

extern signed char D_80070CB8[];
extern void func_8004E7E0(float m[4][4], float angle, float x, float y, float z);
extern void func_80059410(float m[4][4], float x, float y, float z, float *ox, float *oy, float *oz);
extern void func_80024114(float *a, float *b, float *out);
extern void func_80021328(float angle, float *v);
extern void func_800214D0(float *a, float *b);

void func_80024DBC(int arg0, float *pos, Obj *obj, Out3 *out3, Out4 *out4) {
    float b[3];
    float a[3];
    float c[3];
    float m[4][4];
    int pad[8];
    float angle;

    if (D_80070CB8[obj->kind] == 1) {
        angle = 110.0f;
    } else {
        angle = 70.0f;
    }
    if (obj->kind == 2) {
        angle = -70.0f;
    }
    func_8004E7E0(m, angle, obj->x, obj->y, obj->z);
    func_80059410(m, pos[0], pos[1], pos[2], &b[0], &b[1], &b[2]);
    func_8004E7E0(m, 90.0f, obj->x, obj->y, obj->z);
    func_80059410(m, b[0], b[1], b[2], &a[0], &a[1], &a[2]);
    func_80024114(a, b, c);
    out4->x = c[0];
    out4->y = c[1];
    out4->z = c[2];
    pos[1] = 0.0f;
    func_80021328(angle, pos);
    func_800214D0(pos, pos);
    out3->x = pos[0];
    out3->y = 0.0f;
    out3->z = pos[2];
}
