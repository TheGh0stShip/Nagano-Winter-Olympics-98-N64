typedef struct InitBlock {
    int words[30];
} InitBlock;

typedef struct SlotBlock {
    int words[9];
} SlotBlock;

typedef struct Racer {
    unsigned short field_00;
    unsigned short field_02;
    unsigned char field_04;
    unsigned char field_05;
    unsigned char field_06;
    unsigned char pad_07;
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
    int pad_134;
    int field_138;
    unsigned short pad_13C;
    unsigned short field_13E;
    unsigned short field_140;
    unsigned short field_142;
    float field_144;
    float field_148;
    unsigned short field_14C;
    unsigned short field_14E;
    unsigned short field_150;
    unsigned char field_152;
    unsigned char pad_153;
    int field_154;
    SlotBlock slots[20];
} Racer;

extern InitBlock D_8006EED0;
extern SlotBlock D_8006C478;
extern unsigned char *D_80126BF0;

void func_80009AE8(short index) {
    Racer *racer;
    short i;

    racer = (Racer *)(D_80126BF0 + 0x802A8) + index;
    racer->field_00 = 0;
    racer->field_02 = 0;
    racer->field_04 = 0;
    racer->field_05 = 0;
    racer->field_06 = 0;
    racer->field_2C = 0;
    racer->field_2E = 0xFF;
    racer->field_2F = 0xFF;
    racer->field_30 = 0xFF;
    racer->field_31 = 0xFF;
    racer->field_32 = 1;
    racer->field_38 = D_8006EED0;
    racer->field_B0 = D_8006EED0;
    racer->field_08 = 0.0f;
    racer->field_0C = 0.0f;
    racer->field_10 = 0.0f;
    racer->field_14 = 0.0f;
    racer->field_18 = 0.0f;
    racer->field_1C = 0.0f;
    racer->field_20 = 1.0f;
    racer->field_24 = 1.0f;
    racer->field_28 = 1.0f;
    racer->field_128 = 0;
    racer->field_12C = 0;
    racer->field_130 = 0;
    racer->field_138 = 0;
    for (i = 0; i < 20; i++) {
        racer->slots[i] = D_8006C478;
    }
    racer->field_152 = 0;
    racer->field_154 = -1;
    racer->field_13E = 0;
    racer->field_140 = 0;
    racer->field_142 = 0;
    racer->field_144 = 0.0f;
    racer->field_148 = 1.0f;
    racer->field_14C = 0;
    racer->field_14E = 0;
    racer->field_150 = 0;
}
