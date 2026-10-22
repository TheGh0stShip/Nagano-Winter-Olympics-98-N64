typedef struct IndexedRecord {
    unsigned char pad0[4];
    unsigned short value;
    unsigned char pad6[0x142];
} IndexedRecord;

extern unsigned char *D_80126BF0;

IndexedRecord *func_8003EAA8(int index, unsigned short value) {
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x8B2C0) + index;
    record->value = value;
    return record;
}
