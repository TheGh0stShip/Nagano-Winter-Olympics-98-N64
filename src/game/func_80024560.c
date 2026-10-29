typedef struct {
    char pad0[4];
    float pos[3];
    char pad10[0xC];
    float f1C;
    float f20;
    char pad24[0xE];
    unsigned char id;
} Obj;
typedef struct {
    char pad0[4];
    float v[3];
} Vec;
typedef struct { short x, y, z; } V3s;
typedef struct { V3s v[3]; } Tri;

extern void *D_80070C00[];
extern int *D_80070B88[];
extern int *D_80070BB8[];
extern short **D_80070BA0[];
extern float D_80070C2C[];
extern signed char D_80070CB8[];
extern unsigned char D_80070C44[][19];
extern unsigned char D_80136C9D;
extern unsigned char D_80137140;

extern void *func_80005E18(void *, int);
extern float func_80021408(float *, float *);
extern void func_80021758(float, float *, float *);
extern int func_80024CB0(float, unsigned char, Vec *, Vec *);
extern void func_80024DBC(int, float *, Obj *, Vec *, Vec *);
extern void func_80024F4C(int, float *, Obj *, Vec *, Vec *);
extern void func_80025DFC(double *, double *, double *, double *);

#define SGN(x) (((x) < 0.0f) ? -1 : 1)

int func_80024560(Obj *obj, Vec *a1, Vec *a2) {
    int result;
    unsigned char i;
    unsigned char j;
    float *off;
    int *list;
    int *list2;
    Tri *t;
    Tri *tris;
    short **cnts;
    short *cnt;
    float pts[3];
    double dx[3];
    double dy[3];
    double dz[3];
    double nrm[3];
    float n[3];
    float d[3];
    unsigned char k;
    int crossed;
    float diff;
    float tmp[3];
    float dot;
    float rot[3];

    obj->f1C = 0.0f;
    obj->f20 = 0.0f;
    result = 0;
    list = func_80005E18(D_80070C00[D_80136C9D], (int)D_80070B88[obj->id]);
    list2 = func_80005E18(D_80070C00[D_80136C9D], (int)D_80070BB8[obj->id]);
    cnts = D_80070BA0[obj->id];
    for (i = 0; ; i++) {
        if (list[i] == -1) break;
        off = func_80005E18(D_80070C00[D_80136C9D], list[i]);
        if ((float)(off[1] * 0.6) < a2->v[2]) {
            diff = -((float)(off[1] * 0.6) - a2->v[2]);
        } else {
            diff = (float)(off[1] * 0.6) - a2->v[2];
        }
        if (D_80070C2C[D_80136C9D] < diff) {
            continue;
        }
        cnt = cnts[i];
        tris = func_80005E18(D_80070C00[D_80136C9D], list2[i]);
        for (j = 0; j < *cnt; j++) {
            if (D_80136C9D == 0 && i == 15 && (j == 9 || j == 10)) {
                continue;
            }
            for (k = 0; k < 3; k++) {
                pts[k] = off[2] + tris[j].v[k].z;
                pts[k] = pts[k] * 0.6;
                pts[k] -= obj->pos[2];
            }
            crossed = 0;
            if (SGN(pts[0]) != SGN(pts[1])) crossed = 1;
            if (SGN(pts[1]) != SGN(pts[2])) crossed = 1;
            if (SGN(pts[2]) != SGN(pts[0])) crossed = 1;
            if (!crossed) {
                continue;
            }
            result = 0;
            t = (Tri *)((char *)tris + j * 18);
            for (k = 0; k < 3; k++) {
                dx[k] = (double)t->v[k].x - (double)t->v[0].x;
                dy[k] = (double)t->v[k].y - (double)t->v[0].y;
                dz[k] = (double)t->v[k].z - (double)t->v[0].z;
            }
            func_80025DFC(dx, dy, dz, nrm);
            for (k = 0; k < 3; k++) {
                n[k] = nrm[k];
            }
            d[0] = obj->pos[0] - (off[0] + t->v[0].x) * 0.6;
            d[1] = obj->pos[1] - (off[1] + t->v[0].y) * 0.6;
            d[2] = obj->pos[2] - (off[2] + t->v[0].z) * 0.6;
            func_80021758(D_80070CB8[obj->id] * 30, rot, n);
            for (k = 0; k < 3; k++) {
                d[k] = rot[k] + d[k];
            }
            dot = 0.0f;
            for (k = 0; k < 3; k++) {
                dot += n[k] * d[k];
            }
            if (SGN(dot) == D_80070CB8[obj->id]) {
                tmp[0] = a1->v[0];
                tmp[1] = a1->v[1];
                tmp[2] = a1->v[2];
                result = func_80024CB0(func_80021408(n, tmp), obj->id, a1, a2);
                func_80021408(n, tmp);
                if (result != 0) {
                    D_80137140 = D_80070C44[obj->id][i];
                    for (k = 0; k < 3; k++) {
                        pts[k] = n[k];
                    }
                    func_80024DBC(result, pts, obj, a1, a2);
                    for (k = 0; k < 3; k++) {
                        pts[k] = n[k];
                    }
                    func_80024F4C(result, pts, obj, a1, a2);
                }
            }
            if (result != 0) {
                break;
            }
        }
        if (result != 0) {
            break;
        }
    }
    return result;
}
