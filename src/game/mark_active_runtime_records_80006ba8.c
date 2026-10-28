typedef struct LinkedRecord {
    unsigned char pad0[4];
    void *active;
    unsigned char pad8[0x10];
} LinkedRecord;

extern void *D_8006C140[];
extern unsigned char *D_80126BF0;
extern LinkedRecord *func_80005E18(int);
extern void func_80006B64(unsigned short, LinkedRecord *);

void func_80006BA8(short index, void *entry) {
    LinkedRecord *record;
    short i;

    entry = D_8006C140[index];
    if (entry != 0) {
        record = func_80005E18(0);
        i = 0;
        if (record->active != 0) {
            do {
                func_80006B64((unsigned short)i, record);
                *(unsigned short *)(D_80126BF0 + 0x80000 + i * 0x150 + 0x3868) = 3;
                i++;
                record++;
            } while (record->active != 0);
        }
    }
}
