extern float D_801381F8;
extern signed char D_80138214;
extern unsigned char D_801380B8;
extern void func_80039DD4(void);

int func_8003D06C(void) {
    D_801381F8 = D_801381F8 - 0.047123891676382035;
    func_80039DD4();
    if (D_801381F8 <= 0.0f) {
        D_80138214 = 0;
        D_801380B8 = 6;
        D_801381F8 = 0;
        return 1;
    }
    return 0;
}
