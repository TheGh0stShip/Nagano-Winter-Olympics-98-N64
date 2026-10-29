extern int D_801335C0;
extern unsigned short D_801335CA;
extern int D_801335D0;
extern int D_801335D4;
extern unsigned char D_8006C3D0;
extern unsigned short func_80005C48(void);
extern void func_800485AC(int arg0);
extern void func_80030B54(void);
extern int func_80030F70(void);
extern int func_8000DD0C(void);
extern int func_8000DD40(void);

int func_8000DBAC(void) {
    if (D_801335D4 == 0) {
        if (D_8006C3D0 == 0 && D_801335CA != 5 && D_801335CA != 6) {
            if (func_80005C48() & 0x9000) {
                func_800485AC(7);
                func_80030B54();
                D_801335D4++;
            }
        }
    } else if (func_80030F70() != 2) {
        D_801335D0 = 0;
        return 1;
    }
    switch (D_801335C0) {
    case 0:
        if (func_8000DD0C()) {
            D_801335C0 = 1;
        }
        break;
    case 1:
        if (func_8000DD40()) {
            D_801335C0 = 3;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
