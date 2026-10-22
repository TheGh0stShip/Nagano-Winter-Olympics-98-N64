extern unsigned char *D_80126BF0;

typedef struct IndexedRecord {
    unsigned char pad0[0x130];
    int word_value;
    unsigned char pad134[0x14];
} IndexedRecord;

int func_8003EB14(int index) {
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x8B2C0) + index;
    return record->word_value;
}
