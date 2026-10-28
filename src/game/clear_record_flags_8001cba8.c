typedef struct ClockRecord {
    unsigned char active;
    unsigned char first;
    unsigned char second;
    unsigned char pad3;
    float elapsed;
    long long timestamp;
} ClockRecord;

extern ClockRecord D_80136610[];
extern int D_801366B8;
extern int D_801366BC;

void func_8001CBA8(void) {
    ClockRecord *record = D_80136610;
    int i;

    for (i = 0; i < 20; i++, record++) {
        record->second = 0;
        record->first = 0;
    }
    D_801366B8 = 0;
    D_801366BC = 0;
}
