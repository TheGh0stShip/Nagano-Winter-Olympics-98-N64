#include "PR/ultratypes.h"
#include "PR/mbi.h"

typedef struct { float v[9]; } Xf;
typedef struct { unsigned short a; unsigned short b; int c; int d; int e; } Hdr;
typedef struct { int a; int b; } Pair;
typedef struct { int a; int b; int c; } TriRec;
typedef struct { unsigned char count; unsigned char pad[3]; int data; unsigned char rest[0x50]; } Blk;
typedef struct { short v[6]; } SVec;
typedef struct Obj {
    unsigned char pad0[4];
    unsigned char unk4;
    unsigned char unk5;
    unsigned char unk6;
    unsigned char pad7[0x128 - 7];
    int unk128;
    int *unk12C;
    unsigned char pad130[4];
    unsigned short unk134;
    unsigned char pad136[2];
    int unk138;
    unsigned short unk13C;
    unsigned short unk13E;
    unsigned short unk140;
    unsigned short unk142;
    unsigned char pad144[0x158 - 0x144];
    Xf xf[1];
} Obj;

extern void *func_80005E18();
extern void func_800057B0(int, float, float, float, float, float, float, float, float, float);
extern void func_80007F90(int, int);
extern void func_8001FD90(Obj *, unsigned short, unsigned short);
extern void func_8001FED0(unsigned short, Xf *);
extern int D_8006FCD0;
extern int D_8006FD48;
extern int D_8006FD70;
typedef struct { unsigned char pad[0x7C92C]; int tbl[1]; } Big;
extern Big *D_80126BF0;
extern Gfx *D_80126BF4;
extern int D_80126BFC;
extern unsigned char D_80067AA8[];

void func_8001FFB8(Obj *obj) {
    unsigned short i;
    unsigned short j;
    unsigned short k;
    unsigned short row;
    Blk *blk;
    TriRec *tri;
    int tpad;
    Hdr *hdr;
    Pair *p;
    Pair *list;
    Gfx *g;
    int seg;
    SVec *sv;
    unsigned char kind;
    Xf m;
    Xf xf;
    int pad[2];

    hdr = (Hdr *)func_80005E18(obj->unk128, obj->unk138);
    hdr = &hdr[obj->unk140];
    list = func_80005E18(obj->unk128, hdr->c);
    p = list;
    if (obj->unk13C != 0 && obj->unk13E != 4) {
        func_8001FD90(obj, hdr->b, hdr->a);
    }
    obj->unk12C = D_80126BF4;
    if (obj->unk4 != 0) {
        gSPDisplayList(D_80126BF4++, (Gfx *)&D_8006FD70);
    } else {
        gSPDisplayList(D_80126BF4++, (Gfx *)&D_8006FCD0);
        if (obj->unk134 == 1) {
            gSPDisplayList(D_80126BF4++, (Gfx *)&D_8006FD48);
        }
    }
    i = 0;
    row = D_80067AA8[obj->unk5];
    {
        while (p->a != 0 || p->b != 0) {
            if (p->b != 0) {
                xf = obj->xf[i];
                func_800057B0(D_80126BFC, xf.v[0], xf.v[1], xf.v[2], xf.v[3], xf.v[4], xf.v[5], xf.v[6], xf.v[7], xf.v[8]);
                gSPMatrix(D_80126BF4++, (Mtx *)(D_80126BFC + 0x80000000), 4);
                D_80126BFC += 0x40;
                blk = (Blk *)func_80005E18(obj->unk128, p->b, &D_80126BFC);
                blk = &blk[obj->unk134 + row * 4];
                tri = func_80005E18(obj->unk128, (int)&blk->data);
                for (j = 0; j < blk->count; j++) {
                    gDPPipeSync(D_80126BF4++);
                    if (tri[j].a != 0 || tri[j].c != 0) {
                        gSPSegment(D_80126BF4++, 6, D_80126BF0->tbl[tri[j].a]);
                        gSPDisplayList(D_80126BF4++, (Gfx *)tri[j].c);
                    }
                    gDPPipeSync(D_80126BF4++);
                    if (tri[j].b != 0) {
                        gSPSegment(D_80126BF4++, 6, D_80126BF0->tbl[obj->unk128]);
                        gSPDisplayList(D_80126BF4++, (Gfx *)tri[j].b);
                    }
                }
                gSPPopMatrix(D_80126BF4++, 0);
            }
            i++;
            p++;
        }
    }
    if (obj->unk134 == 1) {
        gSPDisplayList(D_80126BF4++, (Gfx *)&D_8006FCD0);
    }
    gSPEndDisplayList(D_80126BF4++);
    p = list;
    seg = hdr->d;
    func_80007F90(seg, hdr->e);
    if (D_80126BF0->tbl[seg] != 0) {
        i = 0;
        {
            while (p->a != 0 || p->b != 0) {
                if (p->a != 0 && p->b != 0) {
                    sv = (SVec *)func_80005E18(seg, (int)(obj->unk142 + (TriRec *)p->a));
                    m.v[0] = sv->v[0];
                    m.v[1] = sv->v[1];
                    m.v[2] = sv->v[2];
                    m.v[3] = sv->v[3];
                    m.v[4] = sv->v[4];
                    m.v[5] = sv->v[5];
                    kind = obj->unk6;
                    if (kind != 5 && kind != 9) {
                        m.v[0] /= 10.0f;
                        m.v[1] /= 10.0f;
                        m.v[2] /= 10.0f;
                        m.v[3] /= 10.0f;
                        m.v[4] /= 10.0f;
                        m.v[5] /= 10.0f;
                    }
                    m.v[8] = 1.0f;
                    m.v[7] = 1.0f;
                    m.v[6] = 1.0f;
                    func_8001FED0(obj->unk134, &m);
                    obj->xf[i] = m;
                }
                i++;
                p++;
            }
        }
    }
}
