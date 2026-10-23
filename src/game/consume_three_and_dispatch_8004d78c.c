extern unsigned char *D_80179920;
extern void func_8004D70C(unsigned char, unsigned char, unsigned char, int);

void func_8004D78C(unsigned char type) {
    unsigned char first;
    unsigned char second;
    int third;

    first = *D_80179920++;
    second = *D_80179920++;
    third = *D_80179920++;
    third = (signed char)third;
    third <<= 8;
    third = (short)third;
    func_8004D70C(type, first, second, third);
}
