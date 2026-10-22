typedef struct ActiveObject {
    unsigned char pad[0x140];
    int active;
} ActiveObject;

extern void func_8001B03C(ActiveObject *);
extern void func_8001B454(ActiveObject *);

void func_8001B008(ActiveObject *object) {
    if (object->active != 0) {
        func_8001B03C(object);
        func_8001B454(object);
    }
}
