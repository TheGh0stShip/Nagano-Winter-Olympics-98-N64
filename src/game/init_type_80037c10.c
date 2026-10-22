extern void func_80037C3C(void *);
void func_80037C10(void *object) {
    func_80037C3C(object);
    *(int *)((char *)object + 8) = 13;
}
