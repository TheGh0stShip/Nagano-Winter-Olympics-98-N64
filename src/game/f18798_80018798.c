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
    unsigned char pad0[0x128];
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

extern Gfx D_0600B498[];
extern Gfx D_0600B498[];
extern unsigned char D_06006A58[];
extern void func_800180A0(int arg0, int unused, unsigned short index, float x, float y);

#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }

void func_80018798(Object *obj) {
    unsigned char *text;
    unsigned char c;
    float x;
    float y;
    Vec3 *pos;

    obj->list = D_80126BF4;
    GFX(0xBC001806, *(unsigned int *)(D_80126BF0 + 0x7C930));
    GFX(0x06000000, (unsigned int)D_0600B498);
    GFX(0xBA001301, 0);
    pos = &D_80135D68[obj->first];
    GFX(0xE7000000, 0);
    GFX(0xFD100000, (unsigned int)D_06006A58);
    GFX(0xE8000000, 0);
    GFX(0xF5000100, 0x07000000);
    GFX(0xE6000000, 0);
    GFX(0xF0000000, 0x073FC000);
    GFX(0xE7000000, 0);
    x = pos->x;
    y = pos->y;
    for (text = D_80135C08[obj->second]; *text != 0; text++) {
        c = *text;
        if (c >= '0' && c <= '9') {
            c -= '0';
        } else if (c >= 'a' && c <= 'z') {
            c -= 'a' - 0x24;
        } else if (c >= 'A' && c <= 'Z') {
            c -= 'A' - 0xA;
        } else if (c == ' ') {
            c = 0xFF;
        } else if (c == ':') {
            c = 0x3E;
        } else if (c == '.') {
            c = 0x3F;
        } else if (c == '-') {
            c = 0x40;
        } else if (c == '/') {
            c = 0x41;
        } else if (c == '(') {
            c = 0x42;
        } else if (c == ')') {
            c = 0x43;
        } else if (c == '&') {
            c = 0x44;
        }
        x += 9.0f;
        if (c != 0xFF) {
            func_800180A0(1, 0, c, x, y);
        }
    }
    GFX(0xBA001301, 0x00080000);
    GFX(0xBC001806, ((unsigned int *)(D_80126BF0 + 0x7C92C))[obj->light]);
    GFX(0xB8000000, 0);
}
