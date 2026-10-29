#include "PR/mbi.h"
typedef struct {
    unsigned short active;
    char pad2[0xA];
    float y;
    char pad10[0x14];
    float sx;
    float sy;
    float sz;
    char pad30[0x12C - 0x30];
    Gfx *dl;
    char pad130[0x138 - 0x130];
} Ent;
typedef struct {
    char pad[0x83EF8];
    Ent e[1];
} Big;
extern Big *D_80126BF0;
extern Gfx *D_80126BF4;
extern Gfx D_0604C4F8[];
extern unsigned char D_80137514;
extern unsigned char D_80137515;
extern unsigned char D_80137516;
extern unsigned short D_80137518;
extern unsigned short D_8013751A;
extern char D_8006BAA8[];
extern float D_80080140;
extern double D_80080148;
extern double D_80080150;
extern void func_80006EE0(int, void *);
extern void func_80012788(void);
extern void func_800127A4(void);
extern void func_8002C670(int, unsigned char);
extern unsigned short func_8002D2B4(int);
extern unsigned char func_8002D2DC(int);

unsigned char func_8002CE90(void) {
    unsigned char ret;
    int pad;
    float d1;
    float d3;
    Ent *e;
    float f;
    float a;
    float c;

    D_80137514 = 0x39;
    e = &D_80126BF0->e[D_80137514];
    switch (D_80137515) {
    case 0:
        ret = 0;
        func_80012788();
        func_80006EE0(7, D_8006BAA8);
        D_80137516 = func_8002D2DC(10);
        D_8013751A = func_8002D2B4(40);
        D_80137518 = 0;
        func_8002C670(7, D_80137514);
        c = D_80080140;
        e->sx = c;
        e->sy = c;
        e->sz = c;
        D_80137515++;
        break;
    case 1:
        f = e->y;
        if (f < 0.0f) {
            a = -f;
        } else {
            a = f;
        }
        d1 = (a + 20.0f) * D_80137516 * D_80080148;
        ret = 0;
        func_80012788();
        e->active = 1;
        e->y += d1;
        if (e->y > 0.0f) {
            D_80137515++;
        }
        break;
    case 2:
        ret = 1;
        func_80012788();
        e->active = 1;
        if (++D_80137518 > D_8013751A) {
            D_80137515++;
        }
        break;
    case 3:
        f = e->y;
        if (f < 0.0f) {
            a = -f;
        } else {
            a = f;
        }
        d3 = (a + 20.0f) * D_80137516 * D_80080150;
        ret = 2;
        func_80012788();
        e->active = 1;
        e->y += d3;
        if (e->y > 300.0f) {
            D_80137515++;
        }
        break;
    default:
        ret = 3;
        func_800127A4();
        e->dl = 0;
        e->active = 0;
        break;
    }
    if (e->active == 1) {
        e->dl = D_80126BF4;
        gSPDisplayList(D_80126BF4++, D_0604C4F8);
        gSPEndDisplayList(D_80126BF4++);
    }
    return ret;
}
