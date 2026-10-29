typedef struct InitBlock {
    int words[30];
} InitBlock;

typedef struct Source {
    short scale;
    short pad_02;
    int field_04;
    int pad_08;
    int field_0C;
    int field_10;
    int field_14;
} Source;

typedef struct Record {
    short field_00;
    unsigned short field_02;
    unsigned char field_04;
    unsigned char pad_05[3];
    float field_08;
    float field_0C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    unsigned short field_2C;
    unsigned char field_2E;
    unsigned char field_2F;
    unsigned char field_30;
    unsigned char field_31;
    unsigned short field_32;
    unsigned char pad_34[4];
    InitBlock field_38;
    InitBlock field_B0;
    float field_128;
    float field_12C;
    float field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
} Record;

extern InitBlock D_8006EED0;

void func_800089F4(Record *record, Source *source) {
    record->field_00 = 1;
    record->field_02 = 0;
    record->field_04 = 0;
    record->field_2C = 0;
    record->field_2E = 0xFF;
    record->field_2F = 0xFF;
    record->field_30 = 0xFF;
    record->field_31 = 0xFF;
    record->field_32 = 1;
    record->field_38 = D_8006EED0;
    record->field_B0 = D_8006EED0;
    record->field_128 = 0.0f;
    record->field_12C = 0.0f;
    record->field_130 = 0.0f;
    record->field_08 = 0.0f;
    record->field_0C = 0.0f;
    record->field_10 = 0.0f;
    record->field_14 = 0.0f;
    record->field_18 = 0.0f;
    record->field_1C = 0.0f;
    record->field_20 = source->scale / 1000.0f;
    record->field_24 = source->scale / 1000.0f;
    record->field_28 = source->scale / 1000.0f;
    record->field_134 = source->field_04;
    record->field_138 = source->field_0C;
    record->field_13C = 0;
    record->field_148 = 0;
    record->field_140 = source->field_14;
    record->field_144 = source->field_10;
}
