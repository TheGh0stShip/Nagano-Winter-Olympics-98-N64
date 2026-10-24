typedef struct ScaleRecord {
    unsigned char pad0[0x44];
    int scale;
} ScaleRecord;

extern double D_80081030;

int func_800553C8(ScaleRecord *record, int value) {
    float result = ((float)value * (float)record->scale) / D_80081030 + 0.5;

    return ((int)result) & -16;
}
