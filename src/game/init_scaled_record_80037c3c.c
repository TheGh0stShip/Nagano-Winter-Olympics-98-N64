typedef struct ScaledRecord {
    unsigned char pad0[8];
    int active;
    int scaled;
    unsigned char pad10[0x10];
    float value;
} ScaledRecord;

extern float D_8008059C;

void func_80037C3C(ScaledRecord *record, int value) {
    record->active = 1;
    record->scaled = (int)((float)value / D_8008059C);
    record->value = 0.0f;
}
