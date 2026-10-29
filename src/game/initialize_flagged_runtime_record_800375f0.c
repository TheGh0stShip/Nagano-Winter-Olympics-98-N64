typedef struct RuntimeRecord {
    unsigned char pad0[4];
    unsigned short flags;
    float value;
    unsigned char padC[0x140];
} RuntimeRecord;

extern unsigned char *D_80126BF0;
extern int func_8003EC10(int, float, float, int);
extern void func_8003839C(int, unsigned long long);
extern void func_8003EBD0(int, float, float);
extern unsigned long long func_800540FC(float);

RuntimeRecord *func_800375F0(int index, register unsigned short flags, float x, float y,
                            float first, float second) {
    RuntimeRecord *record;
    int unused;

    record = (RuntimeRecord *)(D_80126BF0 + 0x8B2C0 + index * 0x148);
    unused = func_8003EC10(index, x, y, 1);
    record->flags = flags;
    if (flags & 0x800) {
        record->value = second;
    } else {
        record->value = first;
        func_8003839C((int)first, func_800540FC(second));
    }
    func_8003EBD0(index, 1.0f, 1.0f);
    return record;
}
