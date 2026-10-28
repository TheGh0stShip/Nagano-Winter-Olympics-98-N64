typedef unsigned short u16;

extern short D_80134016;
extern int D_80134018;
extern void func_80005CAC(void);
extern u16 func_80005C48(void);
extern void func_800104F8(short *value);
extern void func_800485AC(int id);
extern void func_800106E4(short value);
extern void func_8000FCF4(void);
extern void func_80010654(short value);

int func_800105A4(void) {
    u16 buttons[1];
    long long unused;
    int oldValue;

    func_80005CAC();
    buttons[0] = func_80005C48();
    oldValue = D_80134016;
    func_800104F8(&D_80134016);
    if (oldValue != D_80134016) {
        func_800485AC(0x46A);
        func_800106E4(oldValue);
    }
    if (buttons[0] & 0x9000) {
        func_800485AC(0x468);
        func_8000FCF4();
        return 1;
    }
    D_80134018++;
    func_80010654(D_80134016);
    return 0;
}
