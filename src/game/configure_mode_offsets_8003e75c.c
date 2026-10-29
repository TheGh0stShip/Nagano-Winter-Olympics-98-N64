extern unsigned char D_80072AFC;
extern signed char D_8013821A;
extern float D_801381E0;

void func_8003E75C(int *kind, int *offset) {
    *kind = 1;
    *offset = -154;
    D_8013821A = D_80072AFC - 1;
    switch (D_80072AFC) {
        case 4:
            *kind = 3;
            *offset = -118;
            D_8013821A = 0;
            break;
        case 5:
            *kind = 2;
            *offset = -136;
            D_8013821A = 2;
            break;
        case 6:
            *kind = 4;
            *offset = -100;
            D_8013821A = 0;
            break;
    }
    D_801381E0 = D_8013821A * 18;
}
