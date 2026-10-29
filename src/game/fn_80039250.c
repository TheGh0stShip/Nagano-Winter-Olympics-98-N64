extern unsigned char *D_80126BF0;
extern unsigned char D_80072AF8;
extern unsigned char D_80072AFC;
extern unsigned char D_80137DF5;
extern unsigned short D_80137DF0;
extern unsigned char D_8013821F;
extern unsigned char D_80138218;
extern short D_8013821C;
extern unsigned char D_801380B8;
extern unsigned char D_80138214;
extern void func_80038B50(void);
extern void func_8002D960(void);
extern void func_80039128(int);
extern void func_80039A8C(void);
extern void func_8003A120(void);
extern void func_8003ECE4(void);
extern void func_80038E88(int);
extern void func_80038C18(int);
extern void func_8003B044(int);

void func_80039250(void) {
    func_80038B50();
    D_80072AF8 = 1;
    D_80072AFC = 0;
    D_80137DF5 = 1;
    D_80137DF0 = 0x800;
    func_8002D960();
    func_80039128(D_80126BF0[0x977EC]);
    func_80039A8C();
    if (D_80126BF0[0x977F4] == 0) {
        func_8003A120();
    }
    D_8013821F = 0;
    func_8003ECE4();
    D_80138218 = 1;
    D_8013821C = -1;
    D_801380B8 = 6;
    D_80138214 = 0;
    func_80038E88(D_80126BF0[0x977EC]);
    func_80038C18(0);
    func_8003B044(0x19);
}
