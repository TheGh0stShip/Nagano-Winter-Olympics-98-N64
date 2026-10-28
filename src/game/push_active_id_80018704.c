typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Object {
    unsigned char pad0[4];
    short flags;
    unsigned char pad6[0x12E];
    unsigned char second;
    unsigned char pad135[3];
    int id;
    unsigned char first;
    unsigned char pad13D[3];
    Vec3 *position;
} Object;

extern unsigned char D_80135C00;
extern unsigned char D_80135C01;
extern Vec3 D_80135D68[];
extern int D_80135C08[];
void func_80018704(Object *object, int id, int unused, float x, float y, float z) {
    Vec3 *position;

    object->flags = 0x1000;
    object->first = D_80135C01;
    object->second = D_80135C00;
    position = &D_80135D68[D_80135C01++];
    position->x = x;
    position->y = y;
    position->z = z;
    {
        int *p = &D_80135C08[D_80135C00++];
        *p = id;
    }
    object->id = id;
    object->position = position;
}
