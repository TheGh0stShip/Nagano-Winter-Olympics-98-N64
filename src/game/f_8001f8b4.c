extern unsigned char *D_80126BF0;
extern void func_80030DE8(void);
extern void func_80030E30(void);
extern void func_80030E0C(void);
extern void func_80030E54(void);
extern void func_80030CB4(int, float);
extern void func_80030D28(int, float);

void func_8001F8B4(unsigned char mode) {
    D_80126BF0[0x977F6] = mode;
    switch (mode) {
    case 1:
        func_80030DE8();
        break;
    case 3:
        func_80030E30();
        break;
    case 5:
        func_80030E0C();
        break;
    case 6:
        func_80030E54();
        break;
    case 7:
        func_80030CB4(2, 14.0f);
        break;
    case 8:
        func_80030D28(1, 14.0f);
        break;
    }
}
