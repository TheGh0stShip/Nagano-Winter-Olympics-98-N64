extern void func_80057010(void);
extern void func_80056FE0(void);
extern void func_8005A3D0(void *, void *, void *, int);
void func_80055B38(void *object, int field_1c, int field_18) {
    func_8005A3D0(object, func_80057010, func_80056FE0, 6);
    *(int *)((char *)object + 0x14) = 0;
    *(int *)((char *)object + 0x18) = field_18;
    *(int *)((char *)object + 0x1C) = field_1c;
}
