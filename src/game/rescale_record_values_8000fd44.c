typedef struct Record {
    short flag;
    short active;
    unsigned char pad4[0xC];
    float value;
    unsigned char pad14[0x124];
} Record;

extern unsigned char *D_80126BF0;

void func_8000FD44(void) {
    Record *record = (Record *)(D_80126BF0 + 0x83EF8);
    unsigned char i;

    for (i = 0; i < 13; i++, record++) {
        record->active = 1;
        record->value = (int)record->value + (int)record->value / 4454.0f;
    }
}
