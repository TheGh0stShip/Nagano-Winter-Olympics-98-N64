typedef struct RuntimeRecord {
    unsigned short state;
    unsigned short enabled;
    unsigned char pad4[8];
    float first;
    float second;
    float third;
    unsigned char pad18[0xC];
    float scale_x;
    float scale_y;
    float scale_z;
    unsigned char pad30[0x108];
} RuntimeRecord;

extern unsigned char *D_80126BF0;

void func_8001DF00(int index, int state) {
    RuntimeRecord *record;

    record = (RuntimeRecord *)(D_80126BF0 + 0x83EF8) + index;
    record->state = state;
    record->enabled = 1;
    record->scale_x = 1.0f;
    record->scale_y = 1.0f;
    record->scale_z = 1.0f;
    record->first = 0.0f;
    record->second = 0.0f;
    record->third = 0.0f;
}
