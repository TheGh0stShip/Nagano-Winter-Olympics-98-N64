typedef struct PositionedObject {
    unsigned char padding[0x30];
    float x;
    float y;
    float z;
} PositionedObject;

extern void func_80052940(PositionedObject *object);

void func_8005DCD0(PositionedObject *object, float x, float y, float z) {
    func_80052940(object);
    object->x = x;
    object->y = y;
    object->z = z;
}
