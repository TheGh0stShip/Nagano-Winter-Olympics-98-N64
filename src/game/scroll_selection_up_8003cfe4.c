extern signed char D_8013821B;
extern float D_801381FC;
extern unsigned char D_801380B8;
extern int func_80039F94(int index, int direction, float position);

void func_8003CFE4(int index) {
    int result;

    index--;
    if (D_8013821B >= 0) {
        result = func_80039F94(index, 1, D_801381FC);
    } else {
        result = func_80039F94(0, -1, D_801381FC);
    }
    if (result == 1) {
        D_801380B8 = 1;
    }
    D_801381FC = D_801381FC + 0.18849556670552814;
}
