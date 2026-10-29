typedef struct InitBlock {
    int words[30];
} InitBlock;

typedef struct Record {
    unsigned short field_00;
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
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
} Record;

extern InitBlock D_8006EED0;

void func_80009E38(int index) {
    int unused1;
    int unused2;
    Record *record;

    record->field_00 = 0;
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
    record->field_08 = 0.0f;
    record->field_0C = 0.0f;
    record->field_10 = 0.0f;
    record->field_14 = 0.0f;
    record->field_18 = 0.0f;
    record->field_1C = 0.0f;
    record->field_20 = 1.0f;
    record->field_24 = 1.0f;
    record->field_28 = 1.0f;
    record->field_134 = 0;
    record->field_138 = 0;
    record->field_140 = 0;
    record->field_144 = 0;
    record->field_13C = 0;
    record->field_148 = 0;
}
