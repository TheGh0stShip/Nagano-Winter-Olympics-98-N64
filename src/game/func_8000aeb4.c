#include "PR/ultratypes.h"
#include "PR/mbi.h"

typedef struct {
    f32 pad0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x18];
    f32 rx;
    f32 ry;
    f32 rz;
    u8 pad34[0x78 - 0x34];
} Cam;

typedef struct {
    s16 flag;
    u8 pad2[0xA];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0x12C - 0x18];
    Gfx *dl;
    u8 pad130[0x138 - 0x130];
} Obj;

typedef struct {
    u8 pad0[0x7C8D8];
    u16 flags;
    u8 pad7C8DA[0x7FB28 - 0x7C8DA];
    Cam cams[144];
    u8 pad83EA8[0x50];
    Obj objs[1];
} Game;

typedef struct {
    u8 active;
    u8 count;
    u8 pad2[2];
    f32 dist;
    f32 pad8;
    f32 scale;
    s16 cam;
    u8 pad12[0xA];
    s16 obj;
    u8 dl;
    u8 pad1F;
} Shadow;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 s;
    f32 pad10;
} Pt;

extern f32 func_80005550(f32, f32);
extern void func_800057B0(u32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_8002FD50(Obj *, s32, s32, s32, s32, s32, s32);
extern void func_8002FD8C(Obj *, s32, s32, s32);
extern f32 func_8004E9D0(f32);
extern f32 func_8005C4E0(f32);
extern f32 sqrtf(f32);
extern double fabs(double);
#pragma intrinsic(sqrtf)
#pragma intrinsic(fabs)
extern Gfx D_8006C518[];
extern Gfx *D_8006C4E8[];
extern u16 D_8006C54C;
extern u16 D_8006C548[];
extern Game *D_80126BF0;
extern Gfx *D_80126BF4;
extern u32 D_80126BFC;
extern Shadow D_80131920;
extern Pt D_80131940[];

#define WRAP(x) \
    if ((x) < -lim || (x) > lim) { \
        if ((x) > zero) { \
            v = 1; \
        } else { \
            v = -1; \
        } \
        (x) -= rng * (s32)(((x) + v * lim) / rng); \
    }

void func_8000AEB4(void) {
    s16 pad0;
    s16 i;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 ex;
    f32 ey;
    f32 ez;
    f32 X;
    f32 Y;
    f32 Z;
    f32 lim;
    f32 u;
    f32 t;
    f32 hx;
    f32 hy;
    Cam *cam;
    Pt *p;
    f32 zero;
    f32 rng;
    f32 len;
    s32 v;
    f32 vy;
    f32 vz;
    s32 w;
    s32 one;
    s32 m40;
    s32 wff;
    s32 a1;
    s32 a2;
    s32 a3;
    f32 sa;
    f32 cb;
    f32 ce;
    Obj *obj;
    f32 c2;
    f32 s2;

    lim = 300.0f;
    zero = 0.0f;
    rng = 600.0f;
    one = 1;
    m40 = 2;
    wff = 0xFF;
    if (D_80131920.active != 0) {
        func_8002FD8C(&D_80126BF0->objs[D_80131920.obj], wff - ((D_8006C548[2] % 8) >> 2) * 0x30, wff - ((D_8006C548[2] % 8) >> 2) * 0x20, wff - ((D_8006C548[2] % 8) >> 2) * 0x10);
        sa = func_8004E9D0(D_80126BF0->cams[D_80131920.cam].ry * 3.141592653589793 / 180.0);
        cb = func_8005C4E0(D_80126BF0->cams[D_80131920.cam].rx * 3.141592653589793 / 180.0);
        s2 = func_8004E9D0(D_80126BF0->cams[D_80131920.cam].rx * 3.141592653589793 / 180.0);
        c2 = func_8005C4E0(D_80126BF0->cams[D_80131920.cam].ry * 3.141592653589793 / 180.0);
        ce = 128.0f * sa;
        w = 0x7F;
        a1 = cb * ce;
        a2 = -s2 * 128.0f;
        a3 = func_8005C4E0(D_80126BF0->cams[D_80131920.cam].rx * 3.141592653589793 / 180.0) * (128.0f * c2);
        func_8002FD50(&D_80126BF0->objs[D_80131920.obj], w, w, w, a1, a2, a3);
        D_8006C54C = D_8006C54C + one;
        cam = &D_80126BF0->cams[D_80131920.cam];
        t = func_8005C4E0(cam->rx * 3.141592653589793 / 180.0);
        u = func_8004E9D0(cam->ry * 3.141592653589793 / 180.0) * -t;
        vy = func_8004E9D0(cam->rx * 3.141592653589793 / 180.0);
        t = func_8005C4E0(cam->rx * 3.141592653589793 / 180.0);
        vz = func_8005C4E0(cam->ry * 3.141592653589793 / 180.0) * -t;
        t = func_80005550(vy, u) * 180.0f / 3.141592653589793;
        len = sqrtf(u * u + vy * vy);
        u = func_8005C4E0((cam->rz + t) * 3.141592653589793 / 180.0) * len;
        hy = func_8004E9D0((cam->rz + t) * 3.141592653589793 / 180.0) * len;
        X = D_80126BF0->cams[D_80131920.cam].x + D_80131920.dist * u;
        Y = D_80126BF0->cams[D_80131920.cam].y + D_80131920.dist * hy;
        Z = D_80126BF0->cams[D_80131920.cam].z + D_80131920.dist * vz;
        ex = X * 0.3f;
        ey = Y * 0.3f;
        ez = Z * 0.3f;
        WRAP(ex);
        WRAP(ey);
        WRAP(ez);
        if (D_80131920.count != 0) {
            obj = &D_80126BF0->objs[D_80131920.obj];
            D_80126BF0->objs[D_80131920.obj].x = X;
            D_80126BF0->objs[D_80131920.obj].y = Y;
            D_80126BF0->objs[D_80131920.obj].z = Z;
            D_80126BF0->objs[D_80131920.obj].flag = one;
            D_80126BF0->objs[D_80131920.obj].dl = D_80126BF4;
            gSPDisplayList(D_80126BF4++, D_8006C518);
            for (i = 0; i < D_80131920.count; i++) {
                if ((i & 1) != ((D_80126BF0->flags & m40) >> 1)) {
                    p = &D_80131940[i];
                    dx = p->x - ex;
                    dy = p->y - ey;
                    dz = p->z - ez;
                    WRAP(dx);
                    WRAP(dy);
                    WRAP(dz);
                    if (!(16000.0 < fabs(D_80131920.scale * dx)) && !(16000.0 < fabs(D_80131920.scale * dy)) &&
                        !(16000.0 < fabs(D_80131920.scale * dz))) {
                        gDPPipeSync(D_80126BF4++);
                        func_800057B0(D_80126BFC, D_80131920.scale * dx, D_80131920.scale * dy, D_80131920.scale * dz,
                                      D_80126BF0->cams[D_80131920.cam].rx, D_80126BF0->cams[D_80131920.cam].ry,
                                      D_80126BF0->cams[D_80131920.cam].rz, p->s * D_80131920.scale,
                                      p->s * D_80131920.scale, p->s * D_80131920.scale);
                        gSPMatrix(D_80126BF4++, D_80126BFC + 0x80000000, G_MTX_PUSH);
                        gSPDisplayList(D_80126BF4++, D_8006C4E8[D_80131920.dl]);
                        gDPPipeSync(D_80126BF4++);
                        gSPPopMatrix(D_80126BF4++, G_MTX_MODELVIEW);
                        D_80126BFC += 0x40;
                    }
                }
            }
            gDPPipeSync(D_80126BF4++);
            gDPSetAlphaCompare(D_80126BF4++, G_AC_NONE);
            gDPSetBlendColor(D_80126BF4++, 0, 0, 0, 1);
            gSPEndDisplayList(D_80126BF4++);
        }
    }
}
