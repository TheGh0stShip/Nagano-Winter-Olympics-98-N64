extern void func_80008630(void *, float, float, float);
extern void func_80008650(void *, float, float, float);
extern void func_80008670(void *, float, float, float);
extern void func_80008690(void *, unsigned short, int, int, int);
extern void func_800086B0(void *, unsigned short, unsigned char, unsigned char,
                          unsigned char, unsigned char, short, void *);

void func_80009414(void *object, unsigned char *record) {
    func_80008630(object, *(float *)(record + 0x08),
                  *(float *)(record + 0x0C), *(float *)(record + 0x10));
    func_80008650(object, *(float *)(record + 0x14),
                  *(float *)(record + 0x18), *(float *)(record + 0x1C));
    func_80008670(object, *(float *)(record + 0x20),
                  *(float *)(record + 0x24), *(float *)(record + 0x28));
    func_800086B0(object, *(unsigned short *)(record + 0x2C), record[0x2E],
                  record[0x2F], record[0x30], record[0x31],
                  *(short *)(record + 0x32), record + 0x38);
    func_80008690(object, *(unsigned short *)record, 1,
                  *(int *)(record + 0x128), *(int *)(record + 0x12C));
}
