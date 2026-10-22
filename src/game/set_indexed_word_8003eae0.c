typedef struct IndexedRecord {
    unsigned char pad0[0x130];
    int word_value;
    unsigned char pad134[0x14];
} IndexedRecord;

extern unsigned char *D_80126BF0;

IndexedRecord *func_8003EAE0(int index, int value) {
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x8B2C0) + index;
    record->word_value = value;
    return record;
}
