typedef struct RecordFields {
    unsigned char pad0[2];
    unsigned char field2;
    unsigned char pad3[0x2D];
    unsigned char field30;
    unsigned char field31;
    unsigned char field32;
    unsigned char field33;
    short field34;
    unsigned char pad36[2];
    int field38;
} RecordFields;

void func_800086B0(RecordFields *record, unsigned char field2,
                   unsigned char field30, unsigned char field31,
                   unsigned char field32, unsigned char field33,
                   short field34, int field38) {
    record->field2 = field2;
    record->field30 = field30;
    record->field31 = field31;
    record->field32 = field32;
    record->field33 = field33;
    record->field34 = field34;
    record->field38 = field38;
}
