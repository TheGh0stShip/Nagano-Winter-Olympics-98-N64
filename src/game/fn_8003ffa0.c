typedef struct ControllerRecord {
    unsigned int unknown;
    unsigned char name[4];
    unsigned short code;
    unsigned char clear[4];
    unsigned char data[16];
} ControllerRecord;

extern unsigned char *D_80126BF0;
extern unsigned char *D_800730A0[];
extern unsigned char D_800730AC;
extern unsigned char *D_800730A8;
extern int func_80013C24(int, ControllerRecord *, int *);
extern int func_80040A3C(unsigned char, int);
extern void func_80041AD0(unsigned char);

int func_8003FFA0(unsigned char index) {
    short result = 0;
    short i;
    ControllerRecord record;
    int value;

    D_800730A8 = D_80126BF0 + 0x92C78;
    record.code = 0x4134;
    *(unsigned int *)record.name = 0x4E48354A;
    for (i = 0; i < 16; i++) {
        record.data[i] = D_800730A0[D_800730AC][i];
    }
    for (i = 0; i < 4; i++) {
        record.clear[i] = 0;
    }
    if (func_80013C24(0, &record, &value)) {
        result = 1;
    } else if (func_80040A3C(index, value)) {
        result = 1;
    } else {
        func_80041AD0(index);
    }
    return result;
}
