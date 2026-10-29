typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Mtx {
    int m[16];
} Mtx;

typedef struct Item {
    float x;
    float y;
    float z;
    int rest[6];
} Item;

typedef struct Obj {
    unsigned char pad[0x138];
    Gfx *dl;
} Obj;

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern unsigned char D_06002C00[];
extern void func_8005DD18(Mtx *m, float x, float y, float z);

void func_800206F0(Obj *obj) {
    int pad0;
    Mtx *mtx;
    int pad;
    float last[9];
    Item *item;
    unsigned short i;
    Gfx *g;
    float x;

    obj->dl = D_80126BF4;
    D_80126BF4++;
    item = (Item *)(D_80126BF0 + 0x96710);
    for (i = 0; i < 80; i++, mtx++, item++) {
        x = item->x;
        if (x != last[0] || item->y != last[1] || item->z != last[2]) {
            func_8005DD18(mtx, x, item->y, item->z);
            g = D_80126BF4++; g->w0 = 0x01040040; g->w1 = (unsigned int)mtx + 0x80000000;
            g = D_80126BF4++; g->w0 = 0x06000000; g->w1 = (unsigned int)D_06002C00;
            g = D_80126BF4++; g->w0 = 0xBD000000; g->w1 = 0;
            *(Item *)last = *item;
        }
    }
    g = D_80126BF4++; g->w0 = 0xB8000000; g->w1 = 0;
}
