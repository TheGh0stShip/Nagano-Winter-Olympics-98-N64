extern void func_8003A330(int);
extern void func_8001DBE0(void);
extern void func_8001D074(void);
extern void func_8001DDA0(void);
extern int (*D_8006F8EC[])(void);
extern int D_801366E4;
extern float D_801366EC;
extern float D_8007ED34;
extern unsigned char *D_80126BF0;

void func_8001D0A0(void) {
    int result;

    func_8003A330(0);
    func_8001DBE0();
    result = D_8006F8EC[D_801366E4]();
    if (D_801366E4 == 18) {
        if (result == 1) {
            func_8001D074();
            D_80126BF0[0x977EC] = 1;
        }
    } else if (result == 1) {
        D_801366E4++;
    }
    D_801366EC += D_8007ED34;
    func_8001DDA0();
}
