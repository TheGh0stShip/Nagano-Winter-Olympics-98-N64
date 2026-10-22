extern unsigned char *D_80179920;
extern void func_8004D70C(int, unsigned char, unsigned char, int);

void func_8004D664(void) {
    unsigned char first;
    unsigned char second;

    first = *D_80179920++;
    second = *D_80179920++;
    func_8004D70C(1, first, second, 0);
}
