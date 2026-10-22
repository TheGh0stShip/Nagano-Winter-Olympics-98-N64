extern void func_8005A7D0(void);
extern void func_8005A804(void);
extern void func_8005A3D0(void *, void *, void *, int);

void func_80055AA0(void *object) {
    func_8005A3D0(object, func_8005A804, func_8005A7D0, 3);
    *(int *)((char *)object + 0x14) = 0;
    *(int *)((char *)object + 0x18) = 1;
}
