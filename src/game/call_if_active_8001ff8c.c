extern void func_8001FFB8(void *);
void func_8001FF8C(void *object) {
    if (*(int *)((char *)object + 0x138) != 0) {
        func_8001FFB8(object);
    }
}
