typedef struct RuntimeRecord {
    unsigned short kind;
    unsigned char pad2[0xA];
    float x;
    float y;
    float z;
    unsigned char pad18[0x130];
} RuntimeRecord;

extern unsigned char *D_80126BF0;
extern float D_80072AE4;
extern float D_80072AE8;

RuntimeRecord *func_8003EC10(int index, float x, float y, unsigned short kind) {
    RuntimeRecord *record = (RuntimeRecord *)(D_80126BF0 + 0x8B2C0) + index;

    record->x = (int)x + (int)x / D_80072AE4;
    record->y = (int)y + (int)y / D_80072AE8;
    record->z = 0.0f;
    if (record->kind < 2) {
        record->kind = kind;
    }
    return record;
}
