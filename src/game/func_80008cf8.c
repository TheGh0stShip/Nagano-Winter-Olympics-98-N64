typedef struct InitBlock {
    int words[30];
} InitBlock;

typedef struct Source {
    float field_00;
    float field_04;
    float field_08;
    float field_0C;
    float field_10;
    float field_14;
    unsigned short field_18;
    unsigned char pad_1A[2];
    int field_1C;
    int pad_20;
    int field_24;
    int pad_28;
    int field_2C;
} Source;

typedef struct Record {
    short field_00;
    unsigned short field_02;
    unsigned short field_04;
    unsigned char pad_06[2];
    float field_08;
    float field_0C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    unsigned short field_30;
    unsigned char field_32;
    unsigned char field_33;
    unsigned char field_34;
    unsigned char field_35;
    unsigned short field_36;
    InitBlock field_38;
    InitBlock field_B0;
    int field_128;
    int field_12C;
    int field_130;
    unsigned char field_134;
    unsigned char pad_135[3];
    int field_138;
    unsigned char field_13C;
    unsigned char pad_13D[3];
    int field_140;
} Record;

extern InitBlock D_8006EED0;

void func_80008CF8(Record *record, Source *source) {
    record->field_00 = 1;
    record->field_02 = 12;
    record->field_04 = source->field_18;
    record->field_30 = 0;
    record->field_32 = 0xFF;
    record->field_33 = 0xFF;
    record->field_34 = 0xFF;
    record->field_35 = 0xFF;
    record->field_36 = 1;
    record->field_08 = 0.0f;
    record->field_38 = D_8006EED0;
    record->field_B0 = D_8006EED0;
    record->field_0C = source->field_00;
    record->field_10 = source->field_04;
    record->field_14 = source->field_08;
    record->field_18 = 0.0f;
    record->field_1C = 0.0f;
    record->field_20 = 0.0f;
    record->field_24 = source->field_0C;
    record->field_28 = source->field_10;
    record->field_2C = source->field_14;
    record->field_128 = source->field_1C;
    record->field_12C = source->field_24;
    record->field_130 = source->field_2C;
    record->field_134 = 0;
    record->field_13C = 0;
    record->field_138 = 0;
    record->field_140 = 0;
}
