typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

typedef struct DisplayBuffer {
    DisplayCommand commands[0x5308];
} DisplayBuffer;

typedef struct Runtime {
    unsigned char pad0[0x7C8C0];
    short frameIndex;
    short nextFrame;
    short prevFrame;
    unsigned char pad7C8C6[0x2];
    short showMeter;
    unsigned char pad7C8CA[0xE];
    unsigned short counter;
} Runtime;

extern unsigned char *D_80126BF0;
extern DisplayCommand *D_80126BF4;
extern unsigned char *D_80126BFC;
extern unsigned char D_80135C00;
extern unsigned char D_80135C01;
extern unsigned char D_80134DE9;
extern int D_801330D0;
extern unsigned char D_8008C650[];
extern unsigned char D_80130BE0[];
extern unsigned long long D_8008D3B8;
extern unsigned int func_80004528(void *sched);
extern int func_800128FC(int arg);
extern int func_80050BE0(void *arg);
extern int func_80005B34(void);
extern int func_80007F44(void);
extern int func_80001A40(void);
extern int func_80017A3C(void);
extern int func_80000EF4(void);
extern void func_80000FA0(void);
extern int func_80001408(void);
extern int func_8000136C(void);
extern int func_80017C08(void);
extern DisplayCommand *func_8000C710(int index, DisplayCommand *gfx);
extern int func_800045C0(void *sched, DisplayCommand **gfx, unsigned long long time);
extern int func_80000FCC(void);
extern int func_80003EB0(void *sched);
extern int func_80008098(void);
extern int func_8000840C(void);
extern int func_8000C1D4(void);

void func_80000798(void) {
    if (func_80004528(D_8008C650) < 2) {
        func_800128FC(0);
        func_800128FC(2);
        func_80050BE0(D_80130BE0);
        D_80126BF4 = ((DisplayBuffer *)D_80126BF0)[*(short *)(D_80126BF0 + 0x7C8C0)].commands + 0x400;
        D_80126BFC = (unsigned char *)(((DisplayBuffer *)D_80126BF0)[*(short *)(D_80126BF0 + 0x7C8C0)].commands + 0x3FA8);
        D_80135C00 = 0;
        D_80135C01 = 0;
        D_80134DE9 = 0;
        func_80005B34();
        if (*(unsigned short *)(D_80126BF0 + 0x7C8F8) == 0x10 && *(unsigned short *)(D_80126BF0 + 0x7C8F6) == 0x2000) {
            ((Runtime *)D_80126BF0)->showMeter ^= 1;
        }
        func_80007F44();
        func_80001A40();
        if (*(short *)(D_80126BF0 + 0x7C8CE) == 0) {
            if (D_801330D0 == 0) {
                func_80017A3C();
            }
            D_80126BF4 = ((DisplayBuffer *)D_80126BF0)[*(short *)(D_80126BF0 + 0x7C8C0)].commands;
            func_80000EF4();
            func_80000FA0();
            func_80001408();
            func_8000136C();
            if (*(short *)(D_80126BF0 + 0x7C8CC) == 0) {
                if (D_801330D0 == 0) {
                    func_80017C08();
                }
                D_80126BF4 = func_8000C710(*(short *)(D_80126BF0 + 0x7C8C0), D_80126BF4);
                func_80000FA0();
                func_800128FC(3);
                if (*(short *)(D_80126BF0 + 0x7C8C8) != 0) {
                    func_800045C0(D_8008C650, &D_80126BF4, D_8008D3B8);
                }
            }
        } else {
            func_80000EF4();
            func_80000FA0();
        }
        if (!(*(short *)(D_80126BF0 + 0x7C8CC) & 2) &&
            !(*(unsigned short *)(D_80126BF0 + 0x7C8D8) & *(short *)(D_80126BF0 + 0x7C8CA))) {
            ((Runtime *)D_80126BF0)->prevFrame = *(short *)(D_80126BF0 + 0x7C8C2);
            func_80000FCC();
            ((Runtime *)D_80126BF0)->frameIndex = func_80003EB0(D_8008C650);
            ((Runtime *)D_80126BF0)->frameIndex++;
            if (((Runtime *)D_80126BF0)->frameIndex >= 3) {
                ((Runtime *)D_80126BF0)->frameIndex = 0;
            }
        }
        func_80008098();
        func_8000840C();
        func_8000C1D4();
        ((Runtime *)D_80126BF0)->counter++;
    }
}
