extern unsigned char *D_80126BF0;
extern unsigned short D_80063508;
extern void func_80005CAC(void);
extern void func_80005C48(void);
extern void func_80001C00(void);
extern void func_80001C54(void);
extern void func_800020A0(void);
extern void func_80001DE0(void);
extern void func_80001F04(void);
extern void func_80002188(void);
extern void func_80002538(void);
extern void func_80002758(void);
extern void func_80002D3C(void);
extern void func_80003318(void);
extern void func_800033E0(void);
extern void func_80003530(void);

void func_80001A40(void) {
    func_80005CAC();
    func_80005C48();
    *(D_80126BF0 + 0x977F1) = (short)D_80063508;
    switch (D_80063508) {
    case 0:
        func_80001C00();
        D_80063508 = 1;
        break;
    case 1:
        func_80001C54();
        break;
    case 2:
        func_800020A0();
        break;
    case 3:
        func_80001DE0();
        break;
    case 4:
        func_80001F04();
        break;
    case 5:
        func_80002188();
        break;
    case 6:
        func_80002538();
        break;
    case 20:
        func_80002758();
        break;
    case 21:
        func_80002D3C();
        break;
    case 22:
        func_80003318();
        break;
    case 23:
        func_800033E0();
        break;
    case 24:
        func_80003530();
        break;
    default:
        D_80063508 = 0;
        break;
    }
}
