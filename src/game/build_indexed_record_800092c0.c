typedef struct Record {
    unsigned int words[0x52];
} Record;

extern unsigned char *D_80126BF0;
extern void func_80008CF8(Record *, int);

void func_800092C0(short index, unsigned short value, int input) {
    Record record;
    func_80008CF8(&record, input);
    *(unsigned short *)&record = value;
    *((Record *)(D_80126BF0 + 0x8B2C0) + index) = record;
}
