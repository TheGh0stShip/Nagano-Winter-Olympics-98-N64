typedef struct RuntimeRecord {
    signed short enabled;
    signed short limit;
    unsigned char pad04[8];
    float x;
    float y;
    float z;
    unsigned char pad18[0x110];
    unsigned int mode;
    unsigned int value;
    unsigned char pad130[8];
} RuntimeRecord;

extern unsigned char *D_80126BF0;
extern unsigned char D_80134DE8;

void func_80011D2C(void) {
    RuntimeRecord *record = (RuntimeRecord *)(D_80126BF0 + 0x8A078);
    unsigned short index;

    for (index = 0; index < 5; index++, record++) {
        record->enabled = 1;
        record->limit = 15;
        record->z = 0.5f;
        record->y = 0.5f;
        record->x = 0.5f;
        record->mode = 7;
        record->value = 0;
    }
    D_80134DE8 = 0;
}
