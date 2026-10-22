typedef struct IndexedRecord {
    unsigned short state;
    unsigned char pad2[0x12A];
    int value;
    unsigned char pad130[8];
} IndexedRecord;

extern unsigned char *D_80126BF0;

void func_8002CCB8(unsigned short index) {
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x83EF8) + index;
    record->state = 0;
    record->value = 0;
}
