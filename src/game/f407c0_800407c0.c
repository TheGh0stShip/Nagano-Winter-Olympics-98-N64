typedef struct ControllerRecord {
    unsigned int unknown;
    unsigned char name[4];
    unsigned short code;
    unsigned char clear[4];
    unsigned char data[16];
} ControllerRecord;

typedef struct SaveSlot {
    unsigned char data[0x7CC];
} SaveSlot;

extern unsigned char *D_800730A0[];
extern unsigned char D_800730AC;
extern SaveSlot *D_800730A8;
extern int func_80013C24(int, ControllerRecord *, int *);
extern int func_80040A3C(unsigned char, int);

void func_800407C0(void) {
    ControllerRecord record;
    int pad;
    int sub;
    unsigned char i;
    short j;

    record.code = 0x4134;
    *(unsigned int *)record.name = 0x4E48354A;
    for (j = 0; j < 16; j++) {
        record.data[j] = D_800730A0[D_800730AC][j];
    }
    for (j = 0; j < 4; j++) {
        record.clear[j] = 0;
    }
    if (func_80013C24(0, &record, &sub)) {
        for (j = 0; j < 4; j++) {
            D_800730A8[j].data[0] = 0;
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (func_80040A3C(i, sub)) {
                D_800730A8[i].data[0] = 0;
            }
        }
    }
}
