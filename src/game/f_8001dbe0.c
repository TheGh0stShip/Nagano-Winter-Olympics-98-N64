extern int D_801366FC;
extern void (*D_8006F7C8)(int);
extern int func_80030F70(void);

void func_8001DBE0(void) {
    switch (D_801366FC) {
    case 1:
        if (!func_80030F70()) {
            D_801366FC = 0;
            if (D_8006F7C8 != 0) {
                D_8006F7C8(1);
            }
            D_8006F7C8 = 0;
        }
        break;
    case 2:
        if (!func_80030F70()) {
            D_801366FC = 0;
            if (D_8006F7C8 != 0) {
                D_8006F7C8(2);
            }
            D_8006F7C8 = 0;
        }
        break;
    case 3:
        if (!func_80030F70()) {
            D_801366FC = 0;
            if (D_8006F7C8 != 0) {
                D_8006F7C8(3);
            }
            D_8006F7C8 = 0;
        }
        break;
    case 4:
        if (!func_80030F70()) {
            D_801366FC = 0;
            if (D_8006F7C8 != 0) {
                D_8006F7C8(4);
            }
            D_8006F7C8 = 0;
        }
        break;
    }
}
