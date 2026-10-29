typedef struct LinkedRecord {
    unsigned char pad0[0x1C];
    void *active;
    unsigned char pad20[0x10];
} LinkedRecord;

typedef struct InitBlock {
    int words[30];
} InitBlock;

extern InitBlock D_8006C358;
extern void *D_8006C240[];
extern unsigned char *D_80126BF0;
extern LinkedRecord *func_80005E18(int);
extern void func_80006D84(unsigned short, LinkedRecord *);

void func_80006DC8(short index, void *entry) {
    LinkedRecord *record;
    short i;

    *(InitBlock *)(D_80126BF0 + 0x800C8) = D_8006C358;
    entry = D_8006C240[index];
    if (entry != 0) {
        record = func_80005E18(0);
        i = 0;
        if (record->active != 0) {
            do {
                func_80006D84((unsigned short)i, record);
                *(unsigned short *)(D_80126BF0 + 0x88000 + i * 0x148 + 0x32C0) = 3;
                i++;
                record++;
            } while (record->active != 0);
        }
    }
}
