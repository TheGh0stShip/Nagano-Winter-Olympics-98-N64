typedef struct ControllerRecord {
    unsigned int unknown;
    unsigned char name[4];
    unsigned short code;
    unsigned char clear[4];
    unsigned char data[16];
} ControllerRecord;

typedef struct SaveSlot {
    unsigned int data[0x7CC / 4];
} SaveSlot;

extern unsigned char *D_80126BF0;
extern SaveSlot *D_800730A8;
extern unsigned char *D_800730A0[];
extern unsigned char D_800730AC;
extern int func_80013C24(int, ControllerRecord *, int *);
extern short func_80040A3C(unsigned char, int);
extern short func_80040A80(unsigned char, int);

short func_80040248(unsigned char arg0, unsigned char arg1) {
    short result;
    short i;
    ControllerRecord record;
    int out;

    D_800730A8 = (SaveSlot *)(D_80126BF0 + 0x92C78);
    record.code = 0x4134;
    *(unsigned int *)record.name = 0x4E48354A;
    for (i = 0; i < 16; i++) {
        record.data[i] = D_800730A0[D_800730AC][i];
    }
    for (i = 0; i < 4; i++) {
        record.clear[i] = 0;
    }
    if (func_80013C24(0, &record, &out)) {
        result = 1;
    } else if (func_80040A3C(arg1, out)) {
        result = 1;
    } else {
        D_800730A8[arg0] = D_800730A8[arg1];
        result = func_80040A80(arg0, out);
    }
    return result;
}
