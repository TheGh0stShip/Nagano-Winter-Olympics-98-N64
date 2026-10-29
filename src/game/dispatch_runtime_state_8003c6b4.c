extern unsigned char D_80138214;
extern void func_8003969C(void);
extern void func_8003C67C(void);
extern void func_8003CB80(void);
extern void func_8003DC9C(void);
extern void func_8003E898(void);

int func_8003C6B4(int state) {
    if (state == D_80138214) {
        return state;
    }
    switch (D_80138214) {
        case 1:
            func_8003969C();
            break;
        case 2:
            func_8003C67C();
            break;
        case 4:
        case 6:
            func_8003CB80();
            break;
        case 5:
        case 7:
            func_8003DC9C();
            break;
        case 3:
            func_8003E898();
            break;
    }
    return D_80138214;
}
