typedef struct RuntimeBytes {
    unsigned char pad[0x92C78];
    unsigned char values[];
} RuntimeBytes;

typedef struct InputRecord {
    unsigned short buttons;
    unsigned char pad2[2];
    short axis;
    unsigned char pad6[8];
} InputRecord;

extern unsigned char *D_80126BF0;
extern unsigned short D_801376C0;

void func_80031ED0(void) {
    short axis;
    unsigned char packed;

    axis = ((InputRecord *)(D_80126BF0 + 0x7C8F6))[D_80126BF0[0x977EF]].axis;
    axis /= 8;
    axis += 15;
    packed = axis;
    if (((InputRecord *)(D_80126BF0 + 0x7C8F6))[D_80126BF0[0x977EF]].buttons & 0x8000) {
        packed = axis;
        packed |= 0x80;
    }
    ((RuntimeBytes *)D_80126BF0)->values[D_801376C0] = packed;
    D_801376C0++;
    if (D_801376C0 >= 15000) {
        D_801376C0 = 14996;
    }
}
