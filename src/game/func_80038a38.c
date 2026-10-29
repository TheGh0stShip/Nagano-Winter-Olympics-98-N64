typedef struct EffectRecord {
    unsigned char bytes[0x148];
} EffectRecord;

extern unsigned char *D_80126BF0;
extern float D_80072AE8;
extern void func_8003EB80(int, int);
extern void func_8003EBD0(int, float, float);
extern void func_80018704(EffectRecord *record, char *text, int unused, float x, float y, float z);

void func_80038A38(char *text, float x, float y, int index) {
    EffectRecord *record = (EffectRecord *)(D_80126BF0 + 0x8B2C0) + index;
    func_8003EB80(index, 1);
    func_80018704(record, text, 0, (int)x + (int)x / D_80072AE8, (int)y + (int)y / D_80072AE8, 0.0f);
    func_8003EBD0(index, 1.0f, 1.0f);
}
