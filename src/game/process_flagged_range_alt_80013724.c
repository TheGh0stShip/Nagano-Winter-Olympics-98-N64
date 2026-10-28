extern unsigned short D_80135228[];
extern void func_800136DC(int index);

void func_80013724(int start, int end) {
    short i;

    for (i = start; i < end; i++) {
        if (D_80135228[i] != 0) {
            func_800136DC(i);
        }
    }
}
