typedef struct ControllerRecord {
    unsigned int unknown;
    unsigned char name[4];
    unsigned short code;
    unsigned char clear[4];
    unsigned char data[16];
} ControllerRecord;

extern unsigned char *D_80126BF0;
extern unsigned char *D_800730A0[];
extern unsigned char *D_800730A8;
extern unsigned char D_800730AC;
extern int func_80013C24(int, ControllerRecord *, int *);
extern void func_800404EC(signed char output[4]);
extern int func_80040AE0(void);
extern int func_80040CC4(unsigned char, int);

int func_800403A0(unsigned char arg) {
    short result = 0;
    short i;
    ControllerRecord record;
    int value;
    unsigned char count = 0;
    signed char output[4];

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
    } else {
        func_800404EC(output);
        for (i = 0; i < 4; i++) {
            if (output[i] >= 0) {
                count++;
            }
        }
        if (count == 1) {
            result = func_80040AE0();
        } else {
            result = func_80040CC4(arg, value);
        }
    }
    return result;
}
