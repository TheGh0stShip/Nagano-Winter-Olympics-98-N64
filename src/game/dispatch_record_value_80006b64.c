extern void func_80006080(unsigned char *, int, int);
extern void func_8000916C(short, unsigned char, void *);

void func_80006B64(short index, unsigned char *record) {
    unsigned char value;

    func_80006080(&value, *(int *)(record + 4), *(int *)(record + 8));
    func_8000916C(index, value, record);
}
