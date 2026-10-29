typedef struct Obj { unsigned char pad0[8]; float x; float y; float z; } Obj;
typedef struct Actor { unsigned char pad0[0x58]; float h58; } Actor;
typedef struct Origin { float x; float y; float z; } Origin;
typedef struct Seg { short x0; short id; short z0; short x1; short y; short z1; } Seg;

extern void *func_80005E18();
extern void func_8019C29C(float, int);
extern double D_8007FC80;
extern double D_8007FC88;
extern double D_8007FC90;
extern unsigned char D_80136C9D;
extern unsigned short D_80136E90[][11];
extern int D_80070C00[];
extern int D_80070BD0[][3];
extern int D_80070BE8[][3];
extern float D_80070C38[];
extern unsigned short D_80070C0C[];

int func_80025008(obj, actor, side)
    Obj *obj;
    Actor *actor;
    unsigned char side;
{
    unsigned int result[1];
    unsigned short i;
    unsigned short j;
    Origin *org;
    Seg *seg;
    float dy;
    float t0;
    float x0, x1, z0, z1, slope, icpt, dz, dx, hit;
    float ox;
    unsigned int *list[1];
    float oz;
    int padB[7];
    short id;
    double scale;
    int sd;
    unsigned int zone;
    int s12;
    float lim;

    result[0] = 0;
    lim = 0.0f;
    sd = side;
    s12 = side * 12;
    list[0] = func_80005E18(D_80070C00[D_80136C9D], *(int *)((char *)D_80070BD0 + D_80136C9D * 4 + s12));
    if (sd) {}
    for (scale = D_8007FC80, i = 0; ; i++) {
        if (list[0][i] == -1) break;
        org = func_80005E18(D_80070C00[D_80136C9D], list[0][i]);
        t0 = org->y * scale;
        dy = (t0 < obj->y) ? -(t0 - obj->y) : (t0 - obj->y);
        if (D_80070C38[D_80136C9D] < dy) continue;
        seg = func_80005E18(D_80070C00[D_80136C9D],
              ((int *)func_80005E18(D_80070C00[D_80136C9D], *(int *)((char *)D_80070BE8 + D_80136C9D * 4 + s12)))[i]);
        for (j = 0; ; j++) {
            id = seg[j].id; if (id == -1) break;
            t0 = seg[j].y + org->y; t0 = t0 * scale;
            dy = (t0 < obj->y) ? -(t0 - obj->y) : (t0 - obj->y);
            if (dy > 300.0f) continue;
            if (((D_80136E90[side][i] >> j) & 1) == 1) continue;
            ox = obj->x;
            oz = obj->z;
            x0 = (seg[j].x0 + org->x) * scale;
            z0 = (seg[j].z0 + org->z) * scale;
            x1 = (seg[j].x1 + org->x) * scale;
            z1 = (seg[j].z1 + org->z) * scale;
            dx = x1 - x0;
            dz = z1 - z0;
            slope = dz / dx;
            icpt = z0 - slope * x0; if (ox * slope + icpt - oz < lim) {}
            if (ox * slope + icpt - oz >= lim) continue;
            if (D_8007FC88 < dz && dz < D_8007FC90) {
                hit = ox;
            } else { if ((oz - (dx / dz) * -1.0f * ox) - icpt) {}
                hit = ((oz - (dx / dz) * -1.0f * ox) - icpt) / (slope - (dx / dz) * -1.0f);
            }
            if ((int)dz | (int)dx) {} if (icpt) {} if (oz) {} if (icpt) {} if ((int)icpt | (int)-icpt) {} if ((int)z1 | (int)-z1 | (int)(z1 * z1) | (int)(z1 + 1.0f)) {} if (ox) {}
            if (x1 < x0) { t0 = x1; x1 = x0; x0 = t0; }
            if (sd) x1 += 20.0f; else x0 -= 20.0f;
            zone = 1;
            if (hit < x0) zone = 0;
            if (x1 < hit) zone = 2;
            if (side == 1 && zone == 2) result[0] = 1;
            if (sd == 0 && zone == 0) result[0] = 1;
            if (side == 1 && ((int)zone | 0) == 1) { result[0] = 2; func_8019C29C(actor->h58, 0x20); }
            if (sd == 0 && ((int)zone | 0) == 1) { result[0] = 2; func_8019C29C(actor->h58, 0x60); }
            D_80136E90[side][i] = (D_80136E90[side][i] | 0) | D_80070C0C[j];
            goto end;
        }
    }
end:
    return result[0];
}
