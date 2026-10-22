typedef struct EffectRecord {
    unsigned char bytes[0x148];
} EffectRecord;

extern unsigned char *D_80126BF0;
extern unsigned char D_80072B04[];
extern void func_80006D84(unsigned short, void *);
extern void func_8003EBD0(int, float, float);
extern void func_8003EAE0(int, int);

EffectRecord *func_800389B4(int index) {
    EffectRecord *record;
    func_80006D84((unsigned short)index, D_80072B04);
    record = (EffectRecord *)(D_80126BF0 + 0x8B2C0) + index;
    func_8003EBD0(index, 1.0f, 1.0f);
    func_8003EAE0(index, 1);
    return record;
}
