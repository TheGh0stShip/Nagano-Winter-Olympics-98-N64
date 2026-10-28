typedef struct RuntimeRecord {
    unsigned char pad0[4];
    unsigned short state;
    unsigned char pad6[0x126];
    int first;
    int second;
    unsigned char pad134[0x14];
} RuntimeRecord;

extern unsigned char *D_80126BF0;
extern void func_8003EB80(int index, int value);
extern void func_8003EBD0(int index, float x, float y);

void func_8003EA20(int index) {
    RuntimeRecord *record = &((RuntimeRecord *)(D_80126BF0 + 0x8B2C0))[index];

    record->first = 0;
    record->state = 0;
    record->second = 0;
    func_8003EB80(index, 0);
    func_8003EBD0(index, 1.0f, 1.0f);
}
