typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Mtx {
    int m[4][4];
} Mtx;

typedef struct Camera {
    unsigned short active;
    unsigned char pad2[0x76];
} Camera;

typedef struct Record {
    unsigned short state;
    unsigned char pad2[2];
    float eye[3];
    float at[3];
    float up[3];
    int light;
    void *dl;
    unsigned char pad30[4];
    unsigned short colorIndex;
    unsigned char pad36[2];
    void *color;
} Record;

typedef struct Game {
    unsigned char pad[0x7D23C];
    Record records[1];
} Game;

typedef struct ViewData {
    unsigned char pad0[0x1BD40];
    Mtx camera[16][6];
    Mtx light[0xA1];
    unsigned char pad[0x29840 - 0x1D540 - 0xA1 * 0x40];
} ViewData;

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern Mtx D_80135940[];
extern Gfx *D_80135A00[][3];
extern Gfx *D_80135AC0[][3];
extern Gfx D_8006EF48[];
extern unsigned char D_8006C3D0;

extern void func_80016974(void *entries, Camera *origin, short id, short *count);
extern void func_8001745C(void *entries, Camera *origin, short id, short *count);
extern void func_80016A6C(void *entries, Camera *origin, short id, short *count);
extern void func_80016CA4(void *entries, Camera *origin, short id, short *count);
extern void func_80017278(void *entries, Camera *origin, short id, short *count);
extern void func_80016EE0(void *entries, Camera *origin, short id, short *count);
extern void func_800170C0(void *entries, Camera *origin, short id, short *count);
extern void func_800164E0(short index, Mtx *mtx);
extern void func_800529C8(Mtx *m);
extern void func_80001BF4(void);
extern void func_800057B0(Mtx *m, float ex, float ey, float ez, float ax, float ay, float az, float ux, float uy, float uz);
extern void func_8002F9B4(unsigned short index, void *color);

#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }
#define VIEW (*(short *)(D_80126BF0 + 0x7C8C0))
#define CAMERAS ((Camera *)(D_80126BF0 + 0x7FB28))

void func_80017640(Camera *origin, short id, short *count) {
    func_80016974(D_80126BF0 + 0x7F898, origin, id, count);
    func_8001745C(D_80126BF0 + 0x83EF8, origin, id, count);
    func_80016A6C(D_80126BF0 + 0x802A8, origin, id, count);
    func_80016CA4(D_80126BF0 + 0x83868, origin, id, count);
    func_80017278(D_80126BF0 + 0x83EF8, origin, id, count);
    func_80016EE0(D_80126BF0 + 0x8B2C0, origin, id, count);
    func_800170C0(D_80126BF0 + 0x92380, origin, id, count);
}

void func_8001778C(short index, Mtx *mtx, short start, short end, short *extra) {
    Record *rec;
    unsigned short i;
    int count;
    unsigned char *base;
    Mtx *m;

    func_800529C8(&D_80135940[*(short *)(D_80126BF0 + 0x7C8C0)]);
    base = D_80126BF0;
    D_80135AC0[index][*(short *)(base + 0x7C8C0)] = D_80126BF4;
    rec = &((Game *)base)->records[start];
    m = mtx + start;
    GFX(0x06000000, (unsigned int)D_8006EF48);
    count = end - start;
    for (i = 0; i < count; i++, rec++, m++) {
        if (start + i > 0xA0) {
            break;
        }
        if (rec->state != 1) {
            continue;
        }
        if (rec->dl == 0) {
            continue;
        }
        GFX(0x01020040, (unsigned int)&D_80135940[*(short *)(D_80126BF0 + 0x7C8C0)] + 0x80000000);
        GFX(0xE7000000, 0);
        GFX(0xBC001806, *(unsigned int *)(D_80126BF0 + 0x7C92C + rec->light * 4));
        func_80001BF4();
        func_800057B0(m, rec->eye[0], rec->eye[1], rec->eye[2], rec->at[0], rec->at[1], rec->at[2], rec->up[0], rec->up[1], rec->up[2]);
        GFX(0x01000040, (unsigned int)m);
        func_8002F9B4(rec->colorIndex, rec->color);
        GFX(0x06000000, (unsigned int)rec->dl);
    }
    GFX(0xB8000000, 0);
}

void func_80017A3C(void) {
    short reserved[2];
    short count;
    short extra = 0;
    unsigned char *base = D_80126BF0;
    short i;
    Camera *cam;
    Mtx *camMtx;
    Mtx *lightMtx;
    short start;

    for (i = 0; i < 16; i++) {
        D_80135AC0[i][*(short *)(base + 0x7C8C0)] = 0;
        D_80135A00[i][*(short *)(base + 0x7C8C0)] = 0;
    }
    lightMtx = ((ViewData *)base)[*(short *)(base + 0x7C8C0)].light;
    camMtx = ((ViewData *)base)[*(short *)(base + 0x7C8C0)].camera[0];
    count = 0;
    start = 0;
    cam = (Camera *)(base + 0x7FB28);
    for (i = 0; i < 16; i++, cam++, camMtx += 6) {
        if (cam->active == 0) {
            continue;
        }
        func_800164E0(i, camMtx);
        if (D_8006C3D0 == 0 || i == 15) {
            func_80017640(cam, i, &count);
            func_8001778C(i, lightMtx, start, count, &extra);
            start = count;
        }
    }
}

void func_80017C08(void) {
    unsigned short i;
    Camera *cam;

    cam = &CAMERAS[10];
    if (cam->active != 0) {
        if (D_80135A00[10][VIEW] != 0) {
            GFX(0x06000000, (unsigned int)D_80135A00[10][VIEW]);
        }
        if (D_80135AC0[10][VIEW] != 0) {
            GFX(0x06000000, (unsigned int)D_80135AC0[10][VIEW]);
        }
    }
    cam = CAMERAS;
    for (i = 0; i < 16; i++, cam++) {
        if (cam->active == 0) {
            continue;
        }
        if (i == 10) {
            continue;
        }
        if (D_80135A00[i][VIEW] != 0) {
            GFX(0x06000000, (unsigned int)D_80135A00[i][VIEW]);
            if (D_80135AC0[i][VIEW] != 0) {
                GFX(0x06000000, (unsigned int)D_80135AC0[i][VIEW]);
            }
        }
    }
}
