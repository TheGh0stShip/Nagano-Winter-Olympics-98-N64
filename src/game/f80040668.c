typedef struct ControllerRecord {
    unsigned int unknown;
    unsigned char name[4];
    unsigned short code;
    unsigned char clear[4];
    unsigned char data[16];
    unsigned char tail[2];
} ControllerRecord;

extern unsigned char *D_80126BF0;
extern unsigned char *D_800730A0[];
extern unsigned char D_800730AC;
extern unsigned char *D_800730A8;

extern int func_80013C24(int index, ControllerRecord *record, int *result);
extern short func_80040A3C(unsigned char value, int arg);
extern int func_80042354(unsigned char value);

void func_80040668(unsigned char *flags) {
    ControllerRecord record;
    short i;
    unsigned char index;
    int result;

    D_800730A8 = D_80126BF0 + 0x92C78;
    record.code = 0x4134;
    *(unsigned int *)record.name = 0x4E48354A;
    for (i = 0; i < 16; i++) {
        record.data[i] = D_800730A0[D_800730AC][i];
    }
    for (i = 0; i < 4; i++) {
        record.clear[i] = 0;
    }
    if (func_80013C24(0, &record, &result)) {
        *flags &= 0xF0;
    } else {
        for (i = 0; i < 4; i++) {
            index = i;
            if (func_80040A3C(index, result) == 0 && func_80042354(index) != 0) {
                *flags |= 1 << i;
            } else {
                *flags &= 0xFF ^ (1 << i);
            }
        }
    }
}
