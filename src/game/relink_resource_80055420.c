extern void func_8004E720(void *);
extern void func_8004E750(void *, void *);

void func_80055420(unsigned char *owner, void *resource) {
    func_8004E720(resource);
    func_8004E750(resource, owner + 0x14);
}
