typedef struct TargetRecord {
    float x;
    float y;
    float z;
    float dx;
    float dy;
    float dz;
    float rand0[10];
    float rand1[10];
    float rand2[10];
    float scale;
    unsigned char kind;
    unsigned char pad95;
    unsigned short state;
} TargetRecord;

typedef struct Source {
    unsigned char flags;
    unsigned char pad1[3];
    float x;
    float y;
    float z;
    float dx;
    float dy;
    float dz;
    float scale;
} Source;

extern unsigned char D_80137720;
extern TargetRecord D_80137730[];
extern short D_80137860;
extern float D_80137864;
extern unsigned short D_80072AD0;
extern double fabs(double);
#pragma intrinsic(fabs)
extern unsigned int func_80036374(void);

void func_80035508(unsigned char index, Source *src) {
    short i;

    if (index < D_80137720) {
        if (src->scale < 1.0f) {
            D_80137730[index].state = 0;
        } else if (D_80137730[index].state == 0) {
            D_80137730[index].state = 1;
        }
        if (D_80137730[index].state == 0) {
            D_80137730[index].dx = D_80137730[index].dy = D_80137730[index].dz = 0.0f;
        } else if (!(src->flags & 2)) {
            D_80137730[index].dx = D_80137730[index].x - src->x;
            D_80137730[index].dy = D_80137730[index].y - src->y;
            D_80137730[index].dz = D_80137730[index].z - src->z;
            if ((D_80072AD0 & 7) == 0) {
                D_80137730[index].state = D_80137730[index].state % 8 + 1;
            }
        } else {
            D_80137730[index].dx = src->dx;
            D_80137730[index].dy = src->dy;
            D_80137730[index].dz = src->dz;
        }
        D_80137730[index].kind = src->flags;
        D_80137730[index].x = src->x;
        D_80137730[index].y = src->y;
        D_80137730[index].z = src->z;
        if (fabs(D_80137730[index].dx * D_80137860 * D_80137864) > 16000.0) {
            D_80137730[index].dx = 0.0f;
        }
        if (fabs(D_80137730[index].dy * D_80137860 * D_80137864) > 16000.0) {
            D_80137730[index].dy = 0.0f;
        }
        if (fabs(D_80137730[index].dz * D_80137860 * D_80137864) > 16000.0) {
            D_80137730[index].dz = 0.0f;
        }
        D_80137730[index].scale = src->scale;
        for (i = 0; i < D_80137860; i++) {
            D_80137730[index].rand0[i] = (float)func_80036374() / 163840.0f + 0.9f;
            D_80137730[index].rand1[i] = (float)func_80036374() / 163840.0f + 0.9f;
            D_80137730[index].rand2[i] = (float)func_80036374() / 163840.0f + 0.9f;
        }
        D_80072AD0++;
    }
}
