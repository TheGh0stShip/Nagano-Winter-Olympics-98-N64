typedef struct LinkedRecord {
    unsigned char pad0[0x10];
    void *active;
    unsigned char pad14[0x10];
} LinkedRecord;

extern void *D_8006C2C0[];
extern unsigned char *D_80126BF0;
extern LinkedRecord *func_80005E18(int);
extern void func_80006EE0(unsigned short, LinkedRecord *);

void func_80006F24(short index, void *entry) {
    LinkedRecord *record;
    short i;

    entry = D_8006C2C0[index];
    if (entry != 0) {
        record = func_80005E18(0);
        i = 0;
        if (record->active != 0) {
            do {
                func_80006EE0((unsigned short)i, record);
                *(unsigned short *)(D_80126BF0 + 0x80000 + i * 0x138 + 0x3EF8) = 3;
                i++;
                record++;
            } while (record->active != 0);
        }
    }
}
