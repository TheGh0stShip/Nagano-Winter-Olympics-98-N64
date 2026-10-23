typedef struct Record {
    unsigned int words[0x10A];
} Record;

extern unsigned char *D_80126BF0;
extern void func_800086EC(Record *, int);

void func_800090CC(short index, unsigned short value, int input) {
    Record record;

    func_800086EC(&record, input);
    *(unsigned short *)&record = value;
    *((Record *)(D_80126BF0 + 0x802A8) + index) = record;
}
