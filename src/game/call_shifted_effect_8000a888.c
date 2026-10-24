extern unsigned char D_8006C500;
extern void func_8000A470(unsigned char, short, float, float, float,
                          unsigned char);

void func_8000A888(unsigned char type, short index, int unused, float first,
                   float second, float third) {
    func_8000A470(type, index, first, second, third, D_8006C500);
}
