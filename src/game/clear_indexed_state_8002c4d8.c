typedef struct IndexedRecord {
    unsigned short state;
    unsigned char pad2[0x136];
} IndexedRecord;

extern unsigned char *D_80126BF0;

void func_8002C4D8(int unused, short index) {
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x83EF8) + index;
    record->state = 0;
}
