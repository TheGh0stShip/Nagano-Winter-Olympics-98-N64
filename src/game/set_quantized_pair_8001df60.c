typedef struct RuntimeRecord {
    unsigned char pad0[0xC];
    float first;
    float second;
    unsigned char pad14[0x124];
} RuntimeRecord;

extern unsigned char *D_80126BF0;

void func_8001DF60(int index, float first, float second) {
    RuntimeRecord *record;

    record = (RuntimeRecord *)(D_80126BF0 + 0x83EF8) + index;
    record->first = (float)(int)first;
    record->second = (float)(int)second;
}
