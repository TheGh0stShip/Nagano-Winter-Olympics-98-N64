typedef struct RuntimeRecord {
    unsigned char pad0[4];
    short state;
    unsigned char pad6[0xE];
    float value;
    unsigned char pad18[0x110];
    int first;
    int second;
    unsigned char pad130[0x18];
} RuntimeRecord;

extern unsigned char *D_80126BF0;
extern void func_8003EC10(int, float, float, unsigned short);
extern void func_8003EAE0(int, int);
extern void func_8003EBD0(int, float, float);

RuntimeRecord *func_80039004(int index, float x, float y, int first, int second,
                            unsigned short type) {
    RuntimeRecord *record;

    record = (RuntimeRecord *)(D_80126BF0 + 0x8B2C0 + index * 0x148);
    record->state = 0;
    func_8003EC10(index, x, y, type);
    record->value = 0.0f;
    record->first = first;
    record->second = second;
    func_8003EAE0(index, 1);
    func_8003EBD0(index, 1.0f, 1.0f);
    return record;
}
