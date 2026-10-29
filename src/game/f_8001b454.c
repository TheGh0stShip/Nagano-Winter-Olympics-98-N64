typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct TextureObject {
    unsigned char pad0[4];
    unsigned short flags;
    unsigned char pad6[2];
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    short width;
    short height;
    unsigned char pad10[0x124];
    Gfx *gfx;
    unsigned char pad138[8];
    unsigned short *buffer;
} TextureObject;

#define SHIFTL(v, s, w) ((unsigned int)(((unsigned int)(v) & ((0x01 << (w)) - 1)) << (s)))
#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }

extern Gfx *D_80126BF4;
extern Gfx D_8006F440[];
extern short D_801365C0;
extern short D_801365C2;
extern void func_8001B7B0(TextureObject *object, short columns, short rows);

void func_8001B454(TextureObject *object) {
    unsigned short *buffer;
    short columns;
    short rows;

    object->gfx = D_80126BF4;
    GFX(0x06000000, (unsigned int)D_8006F440);
    if (object->flags & 0x8000) {
        GFX(0xBA000E02, 0x8000);
        buffer = object->buffer;
        GFX(0xFD100000, (unsigned int)buffer);
        GFX(0xE8000000, 0);
        GFX(0xF5000100, 0x07000000);
        GFX(0xE6000000, 0);
        GFX(0xF0000000, 0x073FC000);
        GFX(0xE7000000, 0);
        GFX(0xE7000000, 0);
    }
    GFX(0xFC127E24, 0xFFFFF3F9);
    GFX(0xFA000000, SHIFTL(object->a, 0, 8) | SHIFTL(object->r, 24, 8) | SHIFTL(object->g, 16, 8) | SHIFTL(object->b, 8, 8));
    if (object->width % D_801365C0) {
        columns = object->width / D_801365C0 + 1;
    } else {
        columns = object->width / D_801365C0;
    }
    if (object->height % D_801365C2) {
        rows = object->height / D_801365C2 + 1;
    } else {
        rows = object->height / D_801365C2;
    }
    func_8001B7B0(object, columns, rows);
    GFX(0xE7000000, 0);
    GFX(0xBA001301, 0x80000);
    GFX(0xB8000000, 0);
}
