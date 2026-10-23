typedef struct Record {
    unsigned int words[0x54];
} Record;

extern unsigned char *D_80126BF0;
extern void func_800088B8(Record *, int);

void func_8000916C(short index, unsigned short value, int input) {
    Record record;

    func_800088B8(&record, input);
    *(unsigned short *)&record = value;
    *((Record *)(D_80126BF0 + 0x83868) + index) = record;
}
