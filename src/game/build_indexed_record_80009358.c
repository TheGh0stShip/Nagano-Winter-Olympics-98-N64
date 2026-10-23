typedef struct Record {
    unsigned int words[0x4E];
} Record;

extern unsigned char *D_80126BF0;
extern void func_80008E08(Record *, int);

void func_80009358(short index, unsigned short value, int input) {
    Record record;

    func_80008E08(&record, input);
    *(unsigned short *)&record = value;
    *((Record *)(D_80126BF0 + 0x83EF8) + index) = record;
}
