extern void func_80012E78(void *);
void func_80012EE4(void *object, int field_28, int field_2c) {
    func_80012E78(object);
    *(int *)((char *)object + 0x28) = field_28;
    *(int *)((char *)object + 0x2C) = field_2c;
}
