extern unsigned short D_80135228[];
extern void func_80013128(unsigned short, int, int, int);

void func_8001316C(unsigned short index, int first, int second, int third) {
    D_80135228[index] = 1;
    func_80013128(index, first, second, third);
}
