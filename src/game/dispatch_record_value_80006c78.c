extern void func_80006080(unsigned char *, int, int);
extern void func_80009228(short, unsigned char, void *);

void func_80006C78(short index, unsigned char *record) {
    unsigned char value;

    func_80006080(&value, *(int *)record, *(int *)(record + 4));
    func_80009228(index, value, record);
}
