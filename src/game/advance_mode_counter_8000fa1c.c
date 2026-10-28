extern int func_8000F90C(void);
extern unsigned char D_8006D450;

int func_8000FA1C(void) {
    switch (func_8000F90C()) {
        case 0:
            return 0;
        case 1:
            if (D_8006D450 != 0) {
                return 0;
            }
            break;
        case 2:
            if (D_8006D450 >= 2) {
                return 0;
            }
            break;
    }
    D_8006D450++;
    return 1;
}
