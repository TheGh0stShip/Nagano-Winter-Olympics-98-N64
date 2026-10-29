typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

typedef struct Runtime {
    unsigned char pad0[0x7C8C0];
    short frameIndex;
    unsigned char pad7C8C2[0x8];
    short unk7C8CA;
    unsigned char pad7C8CC[0x2];
    short unk7C8CE;
    unsigned char pad7C8D0[0x26];
    unsigned short buttons;
    unsigned char pad7C8F8[0x3C];
    int unk7C934;
} Runtime;

extern Runtime *D_80126BF0;
extern DisplayCommand *D_80126BF4;
extern short D_80063508;
extern short D_80063510;
extern void func_80013404(void);
extern void func_8000C150(void);
extern int func_80013FE8(void);
extern void func_80000EF4(void);
extern void func_80000FA0(void);
extern void func_8000136C(void);
extern int func_80014164(DisplayCommand **list, int arg);

void func_80001C54(void) {
    D_80126BF0->unk7C8CA = 0;
    switch (D_80063510) {
    case 0:
        func_80013404();
        if (D_80126BF0->buttons & 0x1000) {
            func_8000C150();
            if (func_80013FE8()) {
                D_80063508 = 3;
            } else {
                D_80063510 = 1;
            }
        } else {
            D_80063510 = 0;
            D_80063508 = 3;
        }
        break;
    case 1:
        D_80126BF0->unk7C8CE = 1;
        D_80126BF4 = (DisplayCommand *)((unsigned char *)D_80126BF0 + D_80126BF0->frameIndex * 0x29840);
        func_80000EF4();
        func_80000FA0();
        func_8000136C();
        if (func_80014164(&D_80126BF4, D_80126BF0->unk7C934)) {
            D_80063510 = 2;
        }
        break;
    case 2:
        D_80126BF0->unk7C8CE = 0;
        D_80063510 = 0;
        D_80063508 = 3;
        break;
    default:
        D_80063510 = 0;
        break;
    }
}
