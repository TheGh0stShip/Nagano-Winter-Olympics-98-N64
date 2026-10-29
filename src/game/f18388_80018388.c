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

extern unsigned char D_060044F8[];
extern Gfx D_0600B498[];
extern unsigned int func_80005E18(int mode, void *texture);
extern void func_8005DD18(Mtx *m, float x, float y, float z);
extern void func_8001805C(int arg0, int arg1, unsigned short index);

#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }

void func_80018388(Object *obj) {
    unsigned int image;
    unsigned char *text;
    unsigned char c;

    obj->list = D_80126BF4;
    image = func_80005E18(1, D_060044F8);
    GFX(0xBC001806, *(unsigned int *)(D_80126BF0 + 0x7C930));
    GFX(0x06000000, (unsigned int)D_0600B498);
    func_8005DD18(D_80126BFC, D_80135D68[obj->first].x, D_80135D68[obj->first].y, D_80135D68[obj->first].z);
    GFX(0x01040040, (unsigned int)D_80126BFC + 0x80000000);
    D_80126BFC++;
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
        } else if (c == '@') {
            c = 0x45;
        } else if (c == ',') {
            c = 0x46;
        } else if (c == '`') {
            c = 0x47;
        }
        GFX(0x01000040, image);
        if (c != 0xFF) {
            func_8001805C(1, 0, c);
        }
    }
    GFX(0xBD000000, 0);
    GFX(0xE7000000, 0);
    GFX(0xBC001806, ((unsigned int *)(D_80126BF0 + 0x7C92C))[obj->light]);
    GFX(0xB8000000, 0);
}
