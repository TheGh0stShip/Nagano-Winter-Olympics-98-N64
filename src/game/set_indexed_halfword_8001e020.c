typedef struct IndexedRecord {
    unsigned short value;
    unsigned char pad2[0x146];
} IndexedRecord;

extern unsigned char *D_80126BF0;

void func_8001E020(int index, int value) {
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x7F898) + index;
    record->value = value;
}
