typedef struct RuntimeRecord {
    unsigned char pad0[0x10];
    float first;
    float second;
    unsigned char pad18[0x130];
} RuntimeRecord;

extern unsigned char *D_80126BF0;

void func_8001DFC0(int index, float first, float second) {
    RuntimeRecord *record;

    record = (RuntimeRecord *)(D_80126BF0 + 0x7F898) + index;
    record->first = (float)(int)first;
    record->second = (float)(int)second;
}
