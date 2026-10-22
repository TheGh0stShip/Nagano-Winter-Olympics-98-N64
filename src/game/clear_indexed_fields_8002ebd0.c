typedef struct IndexedRecord {
    unsigned char pad0[0x134];
    unsigned short first;
    unsigned char pad136[0xC];
    unsigned short second;
    unsigned char pad144[0x2E4];
} IndexedRecord;

extern unsigned char *D_80126BF0;

void func_8002EBD0(unsigned char index) {
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x802A8) + index;
    record->second = 0;
    record->first = 0;
}
