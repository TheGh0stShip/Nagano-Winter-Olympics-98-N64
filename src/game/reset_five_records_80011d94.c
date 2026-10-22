typedef struct IndexedRecord {
    unsigned short first;
    unsigned short second;
    unsigned char pad4[0x128];
    int value;
    unsigned char pad130[8];
} IndexedRecord;

extern unsigned char *D_80126BF0;
extern unsigned char D_80134DE8;

unsigned char func_80011D94(void) {
    unsigned short i;
    IndexedRecord *record;

    record = (IndexedRecord *)(D_80126BF0 + 0x8A078);
    for (i = 0; i < 5; i++) {
        record++;
        record[-1].value = 0;
        record[-1].first = 0;
        record[-1].second = 0;
    }
    return D_80134DE8;
}
