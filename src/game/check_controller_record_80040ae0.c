typedef struct ControllerRecord {
    unsigned int unknown;
    unsigned char name[4];
    unsigned short code;
    unsigned char clear[4];
    unsigned char data[16];
} ControllerRecord;

extern unsigned char *D_800730A0[];
extern unsigned char D_800730AC;
extern int func_80013BA4(int, ControllerRecord *);

int func_80040AE0(void) {
    short result = 0;
    short i;
    ControllerRecord record;

    *(unsigned int *)record.name = 0x4E48354A;
    record.code = 0x4134;
    for (i = 0; i < 4; i++) {
        record.clear[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        record.data[i] = D_800730A0[D_800730AC][i];
    }
    if (func_80013BA4(0, &record)) {
        result = 1;
    }
    return result;
}
