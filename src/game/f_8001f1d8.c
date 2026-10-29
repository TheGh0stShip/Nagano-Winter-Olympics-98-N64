typedef struct SlotRecord {
    short state;
    unsigned char pad2[0x12A];
    int value;
    unsigned char pad130[0x8];
} SlotRecord;

extern unsigned char *D_80126BF0;

void func_8001F1D8(void) {
    int i;

    for (i = 50; i < 57; i++) {
        ((SlotRecord *)(D_80126BF0 + 0x83EF8))[i].state = 0;
        ((SlotRecord *)(D_80126BF0 + 0x83EF8))[i].value = 0;
    }
}
