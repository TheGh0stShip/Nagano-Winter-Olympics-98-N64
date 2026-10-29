typedef struct Spawn {
    float x;
    float y;
    float z;
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
} Spawn;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Object {
    unsigned char pad0[8];
    float x;
    float y;
    float z;
} Object;

extern unsigned char *D_80126BF0;
extern unsigned short D_8006FDF0;
extern unsigned short D_8006FDEC[];
extern unsigned short D_8006FDE8[];

void func_80020630(Object *obj, Vec3 off, float a, float b, float c, float d, float e, float f) {
    Spawn *s;
    unsigned short i;
    s = 0;
    if (s) {}
    i = D_8006FDEC[2];
    s = &((Spawn *)(D_80126BF0 + 0x96710))[i];
    s->x = obj->x + off.x;
    s->y = obj->y + off.y;
    s->z = obj->z + off.z;
    s->a = a; s->b = b; s->c = c; s->d = d; s->e = e; s->f = f;
    i++;
    D_8006FDF0 = i;
    if (i >= 81) {
        D_8006FDE8[4] = 0;
    }
}

