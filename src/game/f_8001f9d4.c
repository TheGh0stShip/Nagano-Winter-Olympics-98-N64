typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Mtx {
    int m[4][4];
} Mtx;

typedef struct Offset {
    float x;
    float y;
} Offset;

typedef struct Part {
    unsigned char count;
    unsigned char pad1[0x1F];
    int segment;
    unsigned char pad24[4];
    void *dl;
    unsigned char pad2C[8];
    Offset *offsets;
} Part;

typedef struct RuntimeRecord {
    unsigned char pad0[0xC];
    float eye[3];
    float at[3];
    float up[3];
    unsigned char pad30[0xFC];
    Gfx *gfx;
    unsigned char pad130[0x18];
} RuntimeRecord;

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern Mtx *D_80126BFC;
extern void func_80006D84(unsigned short index, void *arg);
extern void func_800057B0(Mtx *m, float ex, float ey, float ez, float ax, float ay, float az, float ux, float uy, float uz);

#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }

void func_8001F9D4(int index, int count, Part *part) {
    RuntimeRecord *record = (RuntimeRecord *)(D_80126BF0 + 0x8B2C0) + index;
    int i;
    int j;
    int n;
    Offset *offset;

    func_80006D84(index, (unsigned char *)part + 4);
    record->gfx = D_80126BF4;
    for (i = 0; i < count; i++, part++) {
        GFX(0xE7000000, 0);
        GFX(0xBC001806, ((unsigned int *)(D_80126BF0 + 0x7C92C))[part->segment]);
        n = part->count;
        offset = part->offsets;
        for (j = 0; j < n; j++, offset++) {
            GFX(0xE7000000, 0);
            func_800057B0(D_80126BFC, record->eye[0] + offset->x, record->eye[1] + offset->y, record->eye[2],
                          record->at[0], record->at[1], record->at[2], record->up[0], record->up[1], record->up[2]);
            GFX(0x01040040, (unsigned int)D_80126BFC + 0x80000000);
            D_80126BFC++;
            GFX(0x06000000, (unsigned int)part->dl);
            GFX(0xBD000000, 0);
        }
    }
    GFX(0xB8000000, 0);
}
