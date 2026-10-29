typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Mtx {
    int m[4][4];
} Mtx;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Object {
    unsigned char pad0[8];
    float kind;
    unsigned char padC[0x29];
    unsigned char alpha;
    unsigned char pad36[0xF2];
    int light;
    Gfx *list;
    unsigned char pad130[4];
    unsigned char second;
    unsigned char pad135[7];
    unsigned char first;
} Object;

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern Mtx *D_80126BFC;
extern Vec3 D_80135D68[];
extern unsigned char *D_80135C08[];

extern Gfx D_06006038[];
extern Gfx D_060060B0[];
extern Gfx D_06006128[];
extern Gfx D_060061D8[];
extern Gfx D_06006288[];
extern Gfx D_06006338[];
extern void func_8005DD18(Mtx *m, float x, float y, float z);

#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }

void func_80018B9C(Object *obj) {
    int reserved;
    unsigned char alpha;
    unsigned char kind;
    Vec3 *pos;

    obj->list = D_80126BF4;
    GFX(0xE7000000, 0);
    GFX(0xBC001806, *(unsigned int *)(D_80126BF0 + 0x7C930));
    pos = &D_80135D68[obj->first];
    alpha = obj->alpha;
    kind = obj->kind;
    func_8005DD18(D_80126BFC, pos->x, pos->y, pos->z);
    GFX(0x01040040, (unsigned int)D_80126BFC + 0x80000000);
    D_80126BFC++;
    GFX(0xE7000000, 0);
    GFX(0xFA000000, (0x20 << 24) | (0x20 << 16) | (0xFF << 8) | (alpha & 0xFF));
    GFX(0xE7000000, 0);
    switch (kind) {
        case 0:
            GFX(0x06000000, (unsigned int)D_06006038);
            GFX(0x06000000, (unsigned int)D_06006128);
            break;
        case 1:
            GFX(0x06000000, (unsigned int)D_060060B0);
            GFX(0x06000000, (unsigned int)D_060061D8);
            break;
        case 2:
            GFX(0x06000000, (unsigned int)D_06006038);
            GFX(0x06000000, (unsigned int)D_06006338);
            break;
        case 3:
            GFX(0x06000000, (unsigned int)D_06006038);
            GFX(0x06000000, (unsigned int)D_06006288);
            break;
    }
    GFX(0xBD000000, 0);
    GFX(0xE7000000, 0);
    GFX(0xBC001806, ((unsigned int *)(D_80126BF0 + 0x7C92C))[obj->light]);
    GFX(0xB8000000, 0);
}
