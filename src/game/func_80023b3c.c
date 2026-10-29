typedef struct Obj {
    unsigned char pad0[4];
    float pos[3];
    float vel[3];
    float pad1C;
    float radius;
    short angle;
    unsigned char pad26[0x54 - 0x26];
    unsigned short state;
} Obj;

typedef struct Src {
    unsigned char pad0[0x10];
    float pos[3];
} Src;

extern double D_8007FC10;
extern double D_8007FC18;
extern float D_8007FC20;
extern float func_80020E70(Obj *, int);
extern void func_80021328(float, float *);
extern float func_80021408(float *, float *);
extern void func_800214D0(float *, float *);
extern void func_800217FC(float, float *);
extern float func_80023D7C(Obj *);
extern float func_80023E3C(Obj *);

void func_80023B3C(int player, Src *src, Obj *obj) {
    int pad2;
    unsigned char hit;
    float ang;
    float vel[3];
    float pos[3];
    float a[3];
    struct { float w; float v[3]; } bb;

    float t;

    hit = 0;
    if (D_8007FC10 < obj->radius) {
        hit = 1;
    } else {
        a[0] = src->pos[0];
        a[1] = src->pos[1];
        a[2] = src->pos[2];
        func_800214D0(a, bb.v);
        bb.v[1] = 0.0f;
        a[0] = obj->pos[0];
        a[1] = obj->pos[1];
        a[2] = obj->pos[2];
        func_80021328((obj->angle * -1.0f) * D_8007FC18, bb.v);
        if (func_80021408(bb.v, a) < obj->radius) {
            hit = 1;
        }
    }
    if (hit) {
        ang = func_80023D7C(obj);
        vel[0] = obj->vel[0];
        vel[1] = obj->vel[1];
        vel[2] = obj->vel[2];
        func_80021328(ang, vel);
        t = func_80023E3C(obj);
        if (func_80020E70(obj, player) > 10.0f) {
            func_800217FC(t, vel);
        }
        if (obj->state == 2) {
            func_800217FC(D_8007FC20, vel);
        }
        obj->vel[0] = vel[0];
        obj->vel[1] = vel[1];
        obj->vel[2] = vel[2];
        pos[0] = obj->pos[0];
        pos[1] = obj->pos[1];
        pos[2] = obj->pos[2];
        func_80021328(ang, pos);
        obj->pos[0] = pos[0];
        obj->pos[1] = pos[1];
        obj->pos[2] = pos[2];
    }
}
