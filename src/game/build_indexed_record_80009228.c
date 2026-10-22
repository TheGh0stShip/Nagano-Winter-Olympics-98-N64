typedef struct Record {
    unsigned int words[0x52];
} Record;

extern unsigned char *D_80126BF0;
extern void func_80008B30(Record *, int);

void func_80009228(short index, unsigned short value, int input) {
    Record record;
    func_80008B30(&record, input);
    *(unsigned short *)&record = value;
    *((Record *)(D_80126BF0 + 0x7F898) + index) = record;
}
