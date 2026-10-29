typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Mtx {
    int m[4][4];
} Mtx;

typedef struct Camera {
    unsigned char pad0[2];
    unsigned char flags;
    unsigned char pad3;
    float eye[3];
    float at[3];
    float up[3];
    float angle[3];
    unsigned char pad34[0xC];
    float fovy;
    float aspect;
    float near;
    float far;
    float scale;
    float left;
    float right;
    float bottom;
    float top;
    unsigned int segment;
    int ulx;
    int uly;
    int lrx;
    int lry;
} Camera;

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern Gfx *D_80135A00[][3];

extern void func_800520C0(Mtx *m, unsigned short *perspNorm, float fovy, float aspect, float near, float far, float scale);
extern void func_8005BF64(Mtx *m, float l, float r, float b, float t, float n, float f, float scale);
extern void func_80052DD8(Mtx *m, float ex, float ey, float ez, float ax, float ay, float az, float ux, float uy, float uz);
extern void func_8005DD18(Mtx *m, float x, float y, float z);
extern void func_8004E974(Mtx *m, float a, float x, float y, float z);

#define _SHIFTL(v, s, w) ((unsigned int)(((unsigned int)(v) & ((0x01 << (w)) - 1)) << (s)))
#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }

void func_800164E0(short index, Mtx *mtx) {
    unsigned short perspNorm;
    Camera *cam;
    int reserved[6];

    D_80135A00[index][*(short *)(D_80126BF0 + 0x7C8C0)] = D_80126BF4;
    cam = (Camera *)(D_80126BF0 + 0x7FB28) + index;
    GFX(0xE7000000, 0);
    GFX(0x03800010, cam->segment);
    if (cam->flags & 2) {
        func_800520C0(mtx, &perspNorm, cam->fovy, cam->aspect, cam->near, cam->far, cam->scale);
        GFX(0xBC00000E, perspNorm);
    } else {
        func_8005BF64(mtx, cam->left, cam->right, cam->bottom, cam->top, cam->near, cam->far, cam->scale);
    }
    GFX(0x01030040, (unsigned int)mtx + 0x80000000);
    if (cam->flags & 1) {
        func_80052DD8(mtx + 1, cam->eye[0], cam->eye[1], cam->eye[2], cam->at[0], cam->at[1], cam->at[2], cam->up[0], cam->up[1], cam->up[2]);
        GFX(0x01010040, (unsigned int)(mtx + 1) + 0x80000000);
    } else {
        {
            float x = cam->at[0];
            float y = cam->at[1];
            float z = cam->at[2];

            func_8005DD18(mtx + 1, -x, -y, -z);
        }
        func_8004E974(mtx + 2, -cam->angle[0], 1.0f, 0.0f, 0.0f);
        func_8004E974(mtx + 3, -cam->angle[1], 0.0f, 1.0f, 0.0f);
        func_8004E974(mtx + 4, -cam->angle[2], 0.0f, 0.0f, 1.0f);
        GFX(0x01010040, (unsigned int)(mtx + 2) + 0x80000000);
        GFX(0x01010040, (unsigned int)(mtx + 3) + 0x80000000);
        GFX(0x01010040, (unsigned int)(mtx + 4) + 0x80000000);
        GFX(0x01010040, (unsigned int)(mtx + 1) + 0x80000000);
    }
    GFX(0xBC000404, 3);
    GFX(0xBC000C04, 3);
    GFX(0xBC001404, 0xFFFD);
    GFX(0xBC001C04, 0xFFFD);
    {
        Gfx *_g = D_80126BF4++;
        _g->w0 = (0xED000000 | _SHIFTL((int)((float)(cam->uly) * 4.0F), 0, 12)) | _SHIFTL((int)((float)(cam->ulx) * 4.0F), 12, 12);
        _g->w1 = _SHIFTL((int)((float)(cam->lry) * 4.0F), 0, 12) | _SHIFTL((int)((float)(cam->lrx) * 4.0F), 12, 12);
    }
    GFX(0xE7000000, 0);
    GFX(0xB8000000, 0);
}
