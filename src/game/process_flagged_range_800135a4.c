extern unsigned short D_80135228[];
extern void func_80013558(int index);

void func_800135A4(int start, int end) {
    short i;

    for (i = start; i < end; i++) {
        if (D_80135228[i] != 0) {
            func_80013558(i);
        }
    }
}
