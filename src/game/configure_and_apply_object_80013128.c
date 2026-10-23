typedef struct Object {
    unsigned char pad[3];
    unsigned char value;
} Object;

extern void func_80012EE4(Object *, int, int);
extern void func_800130E0(Object *);

void func_80013128(unsigned short value, Object *object, int second, int third) {
    func_80012EE4(object, second, third);
    object->value = value;
    func_800130E0(object);
}
