typedef struct InitBlock {
    int words[30];
} InitBlock;

typedef struct Record {
    unsigned short field_00;
    unsigned short field_02;
    unsigned short pad_04;
    unsigned short field_06;
    unsigned char field_08;
    unsigned char field_09;
    unsigned char field_0A;
    unsigned char field_0B;
    unsigned short field_0C;
    unsigned short field_0E;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    unsigned short field_3C;
    unsigned short pad_3E;
    InitBlock field_40;
    InitBlock field_B8;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    int pad_144;
} Record;

extern InitBlock D_8006EED0;
extern InitBlock D_8006C400;
extern unsigned char *D_80126BF0;

void func_80009900(short index) {
    Record *record;

    record = (Record *)(D_80126BF0 + 0x7F898) + index;
    record->field_00 = 0;
    record->field_02 = 10;
    record->field_06 = 0;
    record->field_08 = 0xFF;
    record->field_09 = 0xFF;
    record->field_0A = 0xFF;
    record->field_0B = 0xFF;
    record->field_3C = 1;
    record->field_40 = D_8006EED0;
    record->field_B8 = D_8006EED0;
    record->field_0C = 0;
    record->field_0E = 0;
    record->field_10 = 0.0f;
    record->field_14 = 0.0f;
    record->field_18 = 0.0f;
    record->field_1C = 0.0f;
    record->field_20 = -100.0f;
    record->field_24 = 0.0f;
    record->field_28 = 0.0f;
    record->field_2C = 0.0f;
    record->field_30 = 1.0f;
    record->field_34 = 1.0f;
    record->field_38 = 1.0f;
    record->field_3C = 1;
    record->field_40 = D_8006C400;
    record->field_B8 = D_8006C400;
    record->field_130 = 0;
    record->field_134 = 0;
    record->field_138 = 0;
    record->field_13C = 0;
    record->field_140 = 0;
}
