typedef struct RuntimeRecord {
    unsigned short kind;
    unsigned short pad2;
    unsigned short state;
    unsigned char pad6[6];
    float x;
    float y;
    float z;
    unsigned char pad18[0x110];
    int first;
    int second;
    unsigned char pad130[0x18];
} RuntimeRecord;

extern unsigned char *D_80126BF0;
extern float D_8006F7C0;

RuntimeRecord *func_8001E054(int index, float x, float y, int first, int second, unsigned short kind) {
    RuntimeRecord *record = &((RuntimeRecord *)(D_80126BF0 + 0x8B2C0))[index];

    record->state = 0;
    record->kind = kind;
    record->x = x + D_8006F7C0;
    record->y = y;
    record->z = 0.0f;
    record->first = first;
    record->second = second;
    return record;
}
