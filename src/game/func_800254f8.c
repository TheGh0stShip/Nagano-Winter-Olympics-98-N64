typedef struct { float x; float y; float z; } F3;
typedef struct {
    short x;
    short y;
    short z;
    short pad[5];
} V16;

extern void *D_80071540[];
extern int *D_80070CC0[];
extern int *D_80070CD4[];
typedef struct { unsigned short idx; unsigned short pad; } Ent;
extern Ent *D_8007110C[];
extern float D_80071554[];
extern float D_80071568[];
extern int D_80071120[];
extern int D_80071258[];
extern int D_800713D8[];
extern int D_80071498[];
extern int D_800714C4[];
extern unsigned char D_80136C9D;

extern void *func_80005E18(void *, int);
extern void func_80025DFC(double *, double *, double *, double *);

#define ABSF(x) (((x) < 0.0f) ? -(x) : (x))
#define SGN(x) (((x) < 0.0f) ? -1 : 1)
#define ABSF(x) (((x) < 0.0f) ? -(x) : (x))
#define SGND(x) (((x) < 0.0) ? neg : 1)

int func_800254F8(float *arg0) {
    unsigned short m;
    unsigned short i;
    unsigned short j;
    unsigned char idx;
    unsigned short k;
    F3 *off;
    V16 *v;
    float w[3];
    unsigned char (*tri)[3];
    int *list;
    int *list2;
    Ent *base;
    V16 *verts;
    unsigned int neg;

    unsigned char sa[3];
    unsigned char sb[3];
    unsigned char sc[3];
    double x[3];
    double y[3];
    double z[3];
    double ex[3];
    double ey[3];
    double ez[3];
    double n[3];
    double dx;
    double dz;
    double h;
    unsigned char crossed;
    int result;
    double a1;
    double a3;
    double pa[3];
    double pb[3];
    double pc[3];
    double ra[3];
    double rb[3];
    double rc[3];

    result = 0;
    neg = -1;
    list = func_80005E18(D_80071540[D_80136C9D], (int)D_80070CC0[D_80136C9D]);
    list2 = func_80005E18(D_80071540[D_80136C9D], (int)D_80070CD4[D_80136C9D]);
    base = D_8007110C[D_80136C9D];
    for (i = 0; ; i++) {
        if (neg == list[i]) {
            break;
        }
        if (D_80136C9D == 1 && i == 0x5F) {
            goto end;
        }
        off = func_80005E18(D_80071540[D_80136C9D], list[i]);
        if (D_80071568[D_80136C9D] < ABSF(D_80071554[D_80136C9D] * off->y - arg0[2])) {
            continue;
        }
        k = base[i].idx;
        verts = func_80005E18(D_80071540[D_80136C9D], list2[i]);
        switch (D_80136C9D) {
        case 0:
            tri = func_80005E18(D_80071540[D_80136C9D], D_80071120[i]);
            break;
        case 1:
            tri = func_80005E18(D_80071540[D_80136C9D], D_80071258[i]);
            break;
        case 2:
            tri = func_80005E18(D_80071540[D_80136C9D], D_800713D8[i]);
            break;
        case 3:
            tri = func_80005E18(D_80071540[D_80136C9D], D_80071498[i]);
            break;
        case 4:
            tri = func_80005E18(D_80071540[D_80136C9D], D_800714C4[i]);
            break;
        default:
            tri = func_80005E18(D_80071540[D_80136C9D], D_80071120[i]);
            break;
        }
        for (j = 0; ; j++) {
            if (((unsigned char *)tri)[j * 3] == 0xFF) {
                break;
            }
            {
            for (m = 0; m < 3; m++) {

                idx = tri[j][m];
                crossed = 0;
                v = &((V16 *)((char *)verts + k * 16))[idx];
                x[m] = v->x + (double)off->x;
                y[m] = v->y + (double)off->y;
                z[m] = v->z + (double)off->z;
                if (m) {}
                x[m] *= D_80071554[D_80136C9D];
                y[m] *= D_80071554[D_80136C9D];
                z[m] *= D_80071554[D_80136C9D];
                ex[m] = x[m] - x[0];
                ey[m] = y[m] - y[0];
                ez[m] = z[m] - z[0];
            }
            }
            for (m = 0; m < 3; m++) {
                w[m] = z[m] - arg0[3];
            }
            if (SGN(w[0]) != SGN(w[1])) crossed = 1;
            if (SGN(w[1]) != SGN(w[2])) crossed = 1;
            if (SGN(w[2]) != SGN(w[0])) crossed = 1;
            if (crossed) {
                result = 1;
                func_80025DFC(ex, ey, ez, n);
                a1 = arg0[1];
                a3 = arg0[3];
                dx = a1 - x[0];
                dz = a3 - z[0];
                if (n[1] < 1e-05 && 0.0 <= n[1]) {
                    h = (n[0] * (a1 - x[0]) + (a3 - z[0]) * n[2]) / -1e-05;
                } else if (n[1] < 0.0 && -1e-05 < n[1]) {
                    h = (n[0] * (a1 - x[0]) + (a3 - z[0]) * n[2]) / 1e-05;
                } else {
                    h = (n[0] * (a1 - x[0]) + n[2] * (a3 - z[0])) / (n[1] * -1.0);
                }
                pa[0] = ex[0]; pb[0] = ey[0]; pc[0] = ez[0];
                pa[1] = ex[1]; pb[1] = ey[1]; pc[1] = ez[1];
                pa[2] = dx; pb[2] = h; pc[2] = dz;
                func_80025DFC(pa, pb, pc, ra);
                pa[0] = ex[1]; pb[0] = ey[1]; pc[0] = ez[1];
                pa[1] = ex[2]; pb[1] = ey[2]; pc[1] = ez[2];
                pa[2] = dx; pb[2] = h; pc[2] = dz;
                func_80025DFC(pa, pb, pc, rb);
                pa[0] = ex[2]; pb[0] = ey[2]; pc[0] = ez[2];
                pa[1] = ex[0]; pb[1] = ey[0]; pc[1] = ez[0];
                pa[2] = dx; pb[2] = h; pc[2] = dz;
                func_80025DFC(pa, pb, pc, rc);
                for (m = 0; m < 3; m++) {
                    sa[m] = SGND(ra[m]);
                    sb[m] = SGND(rb[m]);
                    sc[m] = SGND(rc[m]);
                }
                for (m = 0; m < 3; m++) {
                    if (sa[m] != sb[m]) result = 0;
                    if (sb[m] != sc[m]) result = 0;
                    if (sc[m] != sa[m]) result = 0;
                }
                if (result) {
                    arg0[2] = y[0] + h;
                    arg0[4] = n[0];
                    arg0[5] = n[1];
                    arg0[6] = n[2];
                    goto end;
                }
            }
        }
    }
end:
    return result;
}
