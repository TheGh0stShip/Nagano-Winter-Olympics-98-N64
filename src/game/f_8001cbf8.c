typedef struct ClockRecord {
    unsigned char active;
    unsigned char pad1;
    unsigned char started;
    unsigned char pad3;
    float elapsed;
    long long timestamp;
} ClockRecord;

extern ClockRecord D_80136610[];
extern int D_801366B8;
extern void func_8001C89C(unsigned char index, unsigned char arg1, unsigned char arg2);
extern void func_8001C8F0(unsigned char index);

void func_8001CBF8(void) {
    ClockRecord *record = &D_80136610[D_801366B8];

    switch (D_801366B8) {
    case 0:
        if (record->started == 0) {
            record->started++;
            func_8001C89C(0, 0xE8, 0x10);
        }
        func_8001C8F0(0);
        break;
    case 1:
        if (record->started == 0) {
            record->started++;
            func_8001C89C(1, 0xE8, 0x18);
        }
        func_8001C8F0(1);
        break;
    case 2:
        if (record->started == 0) {
            record->started++;
            func_8001C89C(2, 0xE8, 0x20);
        }
        func_8001C8F0(2);
        break;
    case 3:
        break;
    }
    if (record->started == 0) {
        record->started++;
        func_8001C89C(2, 0xE8, 0x20);
    }
    func_8001C8F0(9);
}
