typedef struct IndexedRecord {
    unsigned char pad0[8];
    float value;
    unsigned char padC[0x13C];
} IndexedRecord;

extern unsigned char *D_80126BF0;

IndexedRecord *func_8003EB48(int index, float value) {
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x8B2C0) + index;
    record->value = value;
    return record;
}
