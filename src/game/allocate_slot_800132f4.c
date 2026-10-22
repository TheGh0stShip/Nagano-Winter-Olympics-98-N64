extern unsigned short D_80135228[];
extern void func_8001316C(unsigned short, int, int, int);

void func_800132F4(int first, int second, int third) {
    short i;
    for (i = 0; i < 5; i++) {
        if (D_80135228[i] == 0) {
            func_8001316C(i, first, second, third);
            break;
        }
    }
}
