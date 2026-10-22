typedef struct PairRecord {
    unsigned short state;
    unsigned char pad[0x12A];
    int value;
    unsigned char tail[0x18];
} PairRecord;

extern unsigned char *D_80126BF0;

void func_8000DB7C(void) {
    PairRecord *records = (PairRecord *)(D_80126BF0 + 0x91FA8);
    records[0].state = 0;
    records[0].value = 0;
    records++;
    records->state = 1;
    records->value = 0;
}
