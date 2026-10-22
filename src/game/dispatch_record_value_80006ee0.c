extern void func_80006080(unsigned char *, int, int);
extern void func_80009358(short, unsigned char, void *);

void func_80006EE0(short index, unsigned char *record) {
    unsigned char value;

    func_80006080(&value, *(int *)(record + 0x10), *(int *)(record + 0x14));
    func_80009358(index, value, record);
}
