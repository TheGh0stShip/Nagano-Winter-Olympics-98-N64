typedef struct RuntimeData {
    unsigned char pad0[0x977EF];
    unsigned char flag;
} RuntimeData;

extern RuntimeData *D_80126BF0;
extern unsigned short D_80134082;
extern unsigned short D_80134084;
extern unsigned char D_800636F8[];
extern unsigned char D_8006E590;
extern void func_80007F90(int owner, void *item);
extern int func_80011540(int arg0);
extern void func_801954A0(void);
extern void func_80195544(void);
extern int func_80195598(void);
extern void func_80048580(int arg0);
extern int func_80007170(int mode);

signed char func_80010874(void) {
    signed char result = 0;
    int status;
    short i;

    if (D_80134084 != 0) {
        func_80007F90(0xC, D_800636F8);
    }
    switch (D_80134084) {
    case 0:
        func_80011540(1);
        D_80134084 = 10;
        break;
    case 10:
        if (func_80011540(0)) {
            D_80134084 = 20;
        }
        break;
    case 1:
        func_80011540(1);
        D_80134084 = 11;
        break;
    case 11:
        if (func_80011540(0)) {
            D_80134084 = 21;
        }
        break;
    case 20:
        func_801954A0();
        D_80134084 = 2;
        break;
    case 21:
        func_80195544();
        D_80134084 = 2;
        break;
    case 2:
        result = status = func_80195598();
        if (status == 1) {
            result = 0;
            D_80134084 = 3;
        } else if (status == -1) {
            func_80048580(7);
            for (i = 0; i < 4; i++) {
                D_8006E590 &= (1 << i) ^ 0xFF;
            }
        }
        break;
    case 3:
        D_80126BF0->flag = 0;
        result = func_80007170(0xE);
        break;
    }
    if (result) {
        D_80134082 = 0;
    }
    return result;
}
