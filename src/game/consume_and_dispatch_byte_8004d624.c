extern unsigned char *D_80179920;
extern void func_8004D70C(int, unsigned char, int, int);

void func_8004D624(void) {
    unsigned char value;

    value = *D_80179920++;
    func_8004D70C(0, value, 0, 0);
}
