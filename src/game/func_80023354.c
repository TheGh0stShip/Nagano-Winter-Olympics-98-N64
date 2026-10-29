typedef struct Owner {
    char pad[0x140];
    unsigned short id;
    unsigned short sub;
} Owner;

typedef struct Src {
    char pad[0x10];
    float pos[3];
} Src;

typedef struct Body {
    unsigned char active;
    char pad1[3];
    float vel[3];
    float pos[3];
    char pad1C[4];
    float dot;
    char pad24[0x30];
    unsigned short state;
    char pad56[2];
    float height;
} Body;

extern unsigned char D_80136C9D;
extern float D_80137134;
extern unsigned short D_800708BC[][6];
extern float D_800708E0[][5];

extern float func_80005550(float, float);
extern void func_80021328(float, float *);
extern float func_80021408(float *, float *);
extern void func_800214D0(float *, float *);
extern void func_80021758(float, float *, float *);
extern void func_800217FC(float, float *);
extern float func_80023270(float *);
extern int func_80023A78(unsigned char, unsigned short);
extern void func_80023AB0(float *);

void func_80023354(Owner *arg0, Src *arg1, Body *arg2) {
    unsigned char i;
    int unused;
    float tmp[3];
    float out[3];
    float dir[3];
    float adj[3];
    float s;
    float ang;
    int v;
    unsigned char j;

    tmp[0] = arg1->pos[0];
    tmp[1] = arg1->pos[1];
    tmp[2] = arg1->pos[2];
    func_800214D0(tmp, out);
    dir[0] = out[0];
    dir[1] = 0.0f;
    dir[2] = out[2];
    tmp[0] = arg2->vel[0];
    tmp[1] = arg2->vel[1];
    tmp[2] = arg2->vel[2];
    arg2->dot = func_80021408(dir, tmp);
    ang = func_80005550(out[0], out[2]) * 180.0f / 3.141592653589793;
    func_80021328((float)(func_80005550(arg2->vel[0], arg2->vel[2]) * 180.0f / 3.141592653589793) - ang, dir);
    dir[0] *= 150.0f * (arg2->dot < 0 ? -arg2->dot : arg2->dot);
    dir[1] *= 0;
    dir[2] *= 150.0f * (arg2->dot < 0 ? -arg2->dot : arg2->dot);
    if (out[1] * 5.0f < 0) {
        s = -(out[1] * 5.0f);
    } else {
        s = out[1] * 5.0f;
    }
    tmp[0] = arg2->pos[0];
    tmp[1] = arg2->pos[1];
    tmp[2] = arg2->pos[2];
    func_80021758(s, adj, tmp);
    if (arg2->dot > 0.0f) {
        for (i = 0; i < 3; i++) { dir[i] -= adj[i]; }
    } else {
        for (i = 0; i < 3; i++) { dir[i] += adj[i]; }
    }
    tmp[0] = arg2->pos[0];
    tmp[1] = 0.0f;
    tmp[2] = arg2->pos[2];
    s = func_80023270(tmp);
    dir[0] *= s;
    dir[1] *= 0;
    dir[2] *= s;
    func_80023AB0(dir);
    if (arg2->dot > 0) {
        arg2->pos[0] += dir[0] * 0.01 * 0.6;
        arg2->pos[1] += dir[1] * 0.01 * 0.6;
        arg2->pos[2] += dir[2] * 0.01 * 0.6;
    } else {
        arg2->pos[0] -= dir[0] * 0.01 * 0.6;
        arg2->pos[1] -= dir[1] * 0.01 * 0.6;
        arg2->pos[2] -= dir[2] * 0.01 * 0.6;
    }
    tmp[0] = arg2->pos[0];
    tmp[1] = 0.0f;
    tmp[2] = arg2->pos[2];
    if (arg2->height > 10.0f) {
        for (i = 0;; i++) {
            v = D_800708BC[D_80136C9D][i];
            if ((v | 0) == 0xFFFF) {
                break;
            }
            if ((v | 0) != 0xFFFE && (v | 0) == arg0->id) {
                if (func_80023A78(i, arg0->sub) == 0) {
                    func_800217FC(D_800708E0[D_80136C9D][i], tmp);
                }
                break;
            }
        }
    } else if (arg2->active) {
        func_80021758(10.0f, tmp, tmp);
    }
    switch (D_80136C9D) {
    case 1:
        if (arg2->state == 2) {
            func_800217FC(D_80137134, tmp);
            D_80137134 -= 0.0018;
            if (D_80137134 <= 0.0f) {
                D_80137134 = 0.0f;
            }
        } else if (arg2->state == 8) {
            func_800217FC(D_80137134, tmp);
            D_80137134 -= 0.002;
            if (D_80137134 <= 0.0f) {
                D_80137134 = 0.0f;
            }
        } else {
            D_80137134 = 1.0f;
        }
        break;
    case 2:
        if (arg2->state == 2) {
            func_800217FC(D_80137134, tmp);
            D_80137134 -= 0.002;
            if (D_80137134 <= 0.0f) {
                D_80137134 = 0.0f;
            }
        } else if (arg2->state == 8) {
            func_800217FC(D_80137134, tmp);
            D_80137134 -= 0.002;
            if (D_80137134 <= 0.0f) {
                D_80137134 = 0.0f;
            }
        } else {
            D_80137134 = 1.0f;
        }
        break;
    default:
        if (arg2->state == 8) {
            func_800217FC(D_80137134, tmp);
            D_80137134 -= 0.002;
            if (D_80137134 <= 0.0f) {
                D_80137134 = 0;
            }
        } else {
            D_80137134 = 1.0f;
        }
        break;
    }
    arg2->pos[0] = tmp[0];
    arg2->pos[2] = tmp[2];
}
