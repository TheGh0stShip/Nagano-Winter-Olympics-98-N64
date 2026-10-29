typedef struct Runtime {
    unsigned char pad0[0x977EC];
    unsigned char unk977EC;
    unsigned char pad977ED[2];
    unsigned char unk977EF;
    unsigned char pad977F0[2];
    unsigned char unk977F2;
    unsigned char unk977F3;
    unsigned char pad977F4[3];
    unsigned char unk977F7;
} Runtime;

extern Runtime *D_80126BF0;
extern int D_801340A0;
extern int D_801340A8;
extern void func_8000C150(void);
extern void func_80047750(void);
extern void func_8001F54C(void);
extern void func_800468D0(void);
extern void func_8001CD90(void);
extern void func_80021830(void);
extern void func_80047710(void);
extern void func_80036334(void);
extern void func_8000B924(void);
extern void func_8002C460(void);
extern int func_8002D1D8(void);

void func_800118D0(void) {
    int mode;

    D_801340A0 = 0;
    D_801340A8 = 0;
    D_80126BF0->unk977F3 = 0;
    D_80126BF0->unk977F7 = 0;
    D_80126BF0->unk977F2 = 0;
    D_80126BF0->unk977EF = 0;
    func_8000C150();
    func_80047750();
    func_8001F54C();
    func_800468D0();
    func_8001CD90();
    func_80021830();
    func_80047710();
    func_80036334();
    func_8000B924();
    func_8002C460();
    func_8002D1D8();

    mode = D_80126BF0->unk977EC;
    if (mode != 5 && mode != 4) {
        if (mode < 3) {
            if (mode) {
            }
        }
    }
}
