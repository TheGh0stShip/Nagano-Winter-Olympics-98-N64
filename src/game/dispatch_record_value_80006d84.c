extern void func_80006080(unsigned char *, int, int);
extern void func_800092C0(short, unsigned char, void *);

void func_80006D84(short index, unsigned char *record) {
    unsigned char value;

    func_80006080(&value, *(int *)(record + 0x1C), *(int *)(record + 0x20));
    func_800092C0(index, value, record);
}
