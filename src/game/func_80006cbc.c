typedef struct LinkedRecord {
    unsigned char pad0[8];
    void *active;
    unsigned char padC[0xC];
} LinkedRecord;

typedef struct InitBlock {
    int words[30];
} InitBlock;

extern InitBlock D_800690E0;
extern void *D_8006C1C0[];
extern unsigned char *D_80126BF0;
extern LinkedRecord *func_80005E18(int);
extern void func_80006C78(unsigned short, LinkedRecord *);

void func_80006CBC(short index, void *entry) {
    LinkedRecord *record;
    short i;

    *(InitBlock *)(D_80126BF0 + 0x7FFD8) = D_800690E0;
    entry = D_8006C1C0[index];
    if (entry != 0) {
        record = func_80005E18(0);
        i = 0;
        if (record->active != 0) {
            do {
                func_80006C78((unsigned short)i, record);
                i++;
                record++;
            } while (record->active != 0);
        }
    }
}
