extern void func_80008630(void *, float, float, float);
extern void func_80008650(void *, float, float, float);
extern void func_80008670(void *, float, float, float);
extern void func_80008690(void *, unsigned short, int, int, int);
extern void func_800086B0(void *, unsigned short, unsigned char, unsigned char,
                          unsigned char, unsigned char, short, void *);

void func_80009630(void *object, unsigned char *record) {
    func_80008630(object, *(float *)(record + 0x18),
                  *(float *)(record + 0x1C), *(float *)(record + 0x20));
    func_80008650(object, *(float *)(record + 0x24),
                  *(float *)(record + 0x28), *(float *)(record + 0x2C));
    func_80008670(object, *(float *)(record + 0x30),
                  *(float *)(record + 0x34), *(float *)(record + 0x38));
    func_800086B0(object, *(unsigned short *)(record + 0x06), record[0x08],
                  record[0x09], record[0x0A], record[0x0B],
                  *(short *)(record + 0x3C), record + 0x40);
    func_80008690(object, *(unsigned short *)record, 0,
                  *(int *)(record + 0x130), *(int *)(record + 0x134));
}

