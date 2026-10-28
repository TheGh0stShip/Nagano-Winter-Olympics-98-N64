typedef struct LinkedRecord {
    unsigned char pad0[4];
    void *active;
    unsigned char pad8[0x10];
} LinkedRecord;

typedef struct RuntimeRecord {
    unsigned char pad0[0x2A8];
    unsigned short value;
    unsigned char pad2AA[0x17E];
} RuntimeRecord;

extern void *D_8006C0C0[];
extern unsigned char *D_80126BF0;
extern LinkedRecord *func_80005E18(int);
extern void func_800060E8(unsigned short, LinkedRecord *);

void func_80006A98(short index, void *entry) {
    LinkedRecord *record;
    short i;

    entry = D_8006C0C0[index];
    if (entry != 0) {
        record = func_80005E18(0);
        i = 0;
        while (record->active != 0) {
            RuntimeRecord *runtime;

            func_800060E8((unsigned short)i, record);
            runtime = (RuntimeRecord *)(D_80126BF0 + 0x80000 + i * 0x428);
            if (runtime->value > 0) {
                runtime->value += 5;
            }
            i++;
            record++;
        }
    }
}
