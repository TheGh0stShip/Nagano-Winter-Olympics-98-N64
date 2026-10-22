extern void func_80012E78(void *);
void func_80012EB8(void *object) {
    func_80012E78(object);
    *(int *)((char *)object + 0x28) = 0;
    *(int *)((char *)object + 0x2C) = 0;
}
