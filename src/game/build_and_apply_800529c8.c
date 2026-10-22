typedef struct StackRecord {
    unsigned char bytes[0x40];
} StackRecord;

extern void func_80052940(StackRecord *);
extern void func_80052840(StackRecord *, int);

void func_800529C8(int value) {
    StackRecord record;

    func_80052940(&record);
    func_80052840(&record, value);
}
