typedef struct Object Object;
typedef void (*Callback)(Object *, int, int);

struct Object {
    unsigned char pad[0x28];
    Callback callback;
};

void func_80051770(int unused, Object *object, short value, int argument) {
    object->callback(object, value, argument);
}
