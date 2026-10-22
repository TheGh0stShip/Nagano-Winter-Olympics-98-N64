typedef struct RecordFields {
    unsigned short field_00;
    unsigned char pad_02;
    unsigned char field_03;
    unsigned char pad_04[0x24];
    int field_28;
    int field_2C;
} RecordFields;

void func_80008690(RecordFields *record, unsigned short field_00,
                   unsigned char field_03, int field_28, int field_2C) {
    record->field_00 = field_00;
    record->field_03 = field_03;
    record->field_28 = field_28;
    record->field_2C = field_2C;
}
