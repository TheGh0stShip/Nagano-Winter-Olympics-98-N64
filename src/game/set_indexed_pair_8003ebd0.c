typedef struct IndexedRecord {
    unsigned char pad0[0x24];
    float first;
    float second;
    unsigned char pad2C[0x11C];
} IndexedRecord;

extern unsigned char *D_80126BF0;

IndexedRecord *func_8003EBD0(int index, float first, float second) {
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x8B2C0) + index;
    record->first = first;
    record->second = second;
    return record;
}
