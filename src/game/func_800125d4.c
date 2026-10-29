typedef struct Pad {
    unsigned short buttons;
    unsigned char pad2[12];
} Pad;

typedef struct Runtime {
    unsigned char pad0[0x7C8F0];
    unsigned char active;
    unsigned char locked;
    unsigned char result;
    unsigned char pad7C8F3[5];
    Pad pads[7880];
    unsigned char pad977E8[7];
    unsigned char player;
} Runtime;

extern Runtime *D_80126BF0;
extern signed char D_80134DE8;
extern signed char D_80134DE9;
extern signed char D_80072028;
extern unsigned char func_80011D94(void);
extern void func_80011D2C(void);
extern void func_80011DD8(void);
extern void func_800365B0(void);
extern void func_800365C0(void);
extern void func_800485AC(int);

unsigned char func_800125D4(void) {
    unsigned short buttons;

    if (D_80134DE9 != 0) {
        return D_80126BF0->active;
    }
    D_80134DE9 = 1;
    if (D_80072028 != 0) {
        return 0;
    }
    if (D_80126BF0->locked != 0) {
        return 0;
    }
    buttons = D_80126BF0->pads[D_80126BF0->player].buttons;
    if ((buttons & 0x1000) && D_80134DE8 < 2) {
        if (D_80126BF0->active != 0) {
            D_80126BF0->result = func_80011D94();
            func_800365C0();
            if (D_80126BF0->result == 0) {
                D_80126BF0->active = 0;
            }
            func_800485AC(4);
            return D_80126BF0->active;
        }
        D_80126BF0->active++;
        D_80126BF0->result = 0;
        func_800365B0();
        func_80011D2C();
        func_800485AC(3);
    }
    if (D_80126BF0->active != 0) {
        func_80011DD8();
    }
    return D_80126BF0->active;
}
