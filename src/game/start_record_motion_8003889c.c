typedef struct RuntimeRecord {
    unsigned char data[0x148];
} RuntimeRecord;

extern unsigned char *D_80126BF0;
extern void func_8003EB80(int index, int value);
extern void func_8003EAE0(int index, int value);
extern void func_80019148(RuntimeRecord *record, unsigned char kind, unsigned short type, float x, float y, float z);

void func_8003889C(float x, float y, unsigned short type, int index, unsigned char kind) {
    RuntimeRecord *record = (RuntimeRecord *)(D_80126BF0 + 0x8B2C0) + index;

    func_8003EB80(index, 1);
    func_8003EAE0(index, 1);
    func_80019148(record, kind, type, x, y, 0.0f);
}
