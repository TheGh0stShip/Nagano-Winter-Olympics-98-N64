typedef struct Object {
    unsigned char pad0[4];
    unsigned short flags;
} Object;

extern void func_800196B8(Object *obj, unsigned short mode, unsigned short index);
extern void func_800191D4(Object *obj, unsigned short mode, unsigned short index);
extern void func_80018388(Object *obj);
extern void func_80018B9C(Object *obj);
extern void func_80019CCC(Object *obj, unsigned short index, unsigned short mode, unsigned short sub);

void func_80017E20(Object *obj) {
    unsigned short high;
    unsigned short index;
    int flags;

    high = (obj->flags + obj->flags * 0 + obj->flags * 2 * 0) & 0xFF00;

    if (high & 0x600) {
        index = (unsigned short)((obj->flags & 0xF0) >> 4);
        if (high & 0x100) {
            func_800196B8(obj, (high & 0x200) >> 9, index);
        } else {
            func_800191D4(obj, (high & 0x200) >> 9, index);
        }
    }
    if (high & 0x1000) {
        func_80018388(obj);
    }
    if (high & 0x2000) {
        func_80018B9C(obj);
    }
    if (high & 0x800) {
        flags = obj->flags; index = (flags & 0xF0) >> 4;
        func_80019CCC(obj + (flags = flags + high * 0) * 0, index, (high & 0x300) >> 8, flags & 0xF);
    }
}
