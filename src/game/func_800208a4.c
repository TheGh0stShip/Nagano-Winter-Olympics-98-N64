#include "PR/ultratypes.h"
#include "PR/mbi.h"

typedef struct Node {
    float x, y, z;
    float sx, sy, sz;
    float rx, ry, rz;
} Node;

typedef struct Entry {
    int node;
    Gfx *dl;
} Entry;

typedef struct Holder {
    int pad0;
    int list;
} Holder;

typedef struct Model {
    unsigned char pad0[8];
    float x, y, z;
    unsigned char pad14[0x134 - 0x14];
    int table;
    Gfx *dlStart;
    unsigned char pad13C[0x144 - 0x13C];
    int root;
} Model;

typedef struct Cam {
    int pad0;
    float x, y, z;
} Cam;

extern Gfx *D_80126BF4;
extern Mtx *D_80126BFC;
extern Gfx D_8006FF20[];
extern double D_8007EE50;
extern float D_8007EE58;
extern float D_8007EE5C;
extern void *func_80005E18(void *, unsigned int);
extern void func_800057B0(Mtx *, float, float, float, float, float, float, float, float, float);

void func_800208A4(Model *m, Cam *cam) {
    Entry *e;
    Node *n;
    unsigned short drawn;
    unsigned short count;
    float x, y, z;
    double scale;
    float f;
    float max;
    float min;
    int root;

    root = m->root;
    if (root != 0) {
        m->dlStart = D_80126BF4;
        e = (Entry *)func_80005E18((void *)m->table, ((Holder *)func_80005E18((void *)m->table, root))->list);
        gSPDisplayList(D_80126BF4++, D_8006FF20);
        drawn = 0;
        count = 0;
        while (e->node != 0 || e->dl != 0) {
            {
                scale = 0.6;
                max = 12000.0f;
                min = -12000.0f;
                if (e->dl != 0 && e->node != 0) {
                    n = (Node *)func_80005E18((void *)m->table, e->node);
                    f = (n->y - m->y) * scale;
                    y = f - cam->y;
                    if (!(max < y) && !(y < min)) {
                        f = (n->x - m->x) * scale;
                    x = f - cam->x;
                        if (!(max < x) && !(x < min)) {
                            f = (n->z - m->z) * scale;
                    z = f - cam->z;
                            if (!(max < z) && !(z < min)) {
                                gDPPipeSync(D_80126BF4++);
                                drawn++;
                                func_800057B0(D_80126BFC, x, y, z, n->sx, n->sy, n->sz,
                                              n->rx * scale, n->ry * scale, n->rz * scale);
                                gSPMatrix(D_80126BF4++, (unsigned int)D_80126BFC + 0x80000000, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
                                count++;
                                D_80126BFC++;
                                gSPDisplayList(D_80126BF4++, e->dl);
                                gSPPopMatrix(D_80126BF4++, G_MTX_MODELVIEW);
                            }
                        }
                    }
                }
                e++;
            }
        }
        gDPPipeSync(D_80126BF4++);
        gSPEndDisplayList(D_80126BF4++);
    }
}
