typedef struct IndexedRecord {
    unsigned short state;
    unsigned char pad2[0x146];
} IndexedRecord;

extern unsigned char *D_80126BF0;

IndexedRecord *func_8003EB80(int index, unsigned short value) {
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x8B2C0) + index;
    if (record->state < 2) {
        record->state = value;
    }
    return record;
}
