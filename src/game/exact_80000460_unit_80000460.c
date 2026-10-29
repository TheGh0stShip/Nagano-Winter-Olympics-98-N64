extern void func_800513C0(void);
extern void func_80001650(void);
extern void func_80050A90(void *thread, int id, void (*entry)(void *), void *arg, void *stack, int priority);
extern void func_8005F810(void *thread);
extern void func_800004C4(void *arg);
extern unsigned char D_80083E58[];
extern unsigned char D_80088008[];

void func_80000460(void) {
    func_800513C0();
    func_80001650();
    func_80050A90(D_80083E58, 1, func_800004C4, 0, D_80088008, 9);
    func_8005F810(D_80083E58);
}

extern void func_80058BA0(int priority, void *queue, void *messages, int count);
extern void func_8005AD20(void *thread, int priority);
extern void func_80000550(void *arg);
extern unsigned char D_8008C1B8[];
extern unsigned char D_8008C1D0[];

void func_800004C4(void *arg) {
    func_80058BA0(150, D_8008C1B8, D_8008C1D0, 200);
    func_80050A90(D_80088008, 3, func_80000550, arg, D_8008C1B8, 10);
    func_8005F810(D_80088008);
    func_8005AD20(0, 0);
    for (;;) {
    }
}

typedef struct {
    short state;
    unsigned char pad[0x1E];
} Mode;

extern int osTvType;
extern void func_80003BB0(void);
extern void func_8005A5D0(void *queue, void *messages, int count);
extern void func_800016AC(void);
extern void func_80003C80(void *sched, unsigned int mode, int arg);
extern void func_80003F60(void *sched, void *client, void *queue);
extern int func_80003EA8(void *sched);
extern int func_80003EA0(void *sched);
extern int func_80003EB0(void *sched);
extern void func_8005C650(int arg);
extern void func_80005A20(void);
extern void func_80013934(void);
extern void func_80048080(void);
extern void func_8001C3F0(void);
extern int func_8004E540(void *queue, void *msg, int flag);
extern unsigned long long func_8005B340(void);
extern unsigned long long func_8004F088(unsigned long long a, unsigned long long b);
extern unsigned long long func_8004EF88(unsigned long long a, unsigned long long b);
extern void func_80000B20(void);
extern void func_80000798(void);
extern void func_800128FC(int arg);
extern Mode D_80081DF8[3];
extern unsigned char D_8008C4F0[];
extern unsigned char D_8008C508[];
extern unsigned char D_80081DE0[];
extern unsigned char D_8008C510[];
extern unsigned char D_8008C650[];
extern int D_8008F3C0;
extern int D_8008F3C4;
extern unsigned short D_800634E4;
extern unsigned long long D_8007C990;
unsigned long long D_8008D3B8;
extern unsigned char *D_80126BF0;

void func_80000550(void *arg) {
    unsigned char client[8];
    short *msg = 0;
    unsigned long long start;

    func_80003BB0();
    D_80081DF8[0].state = 2;
    D_80081DF8[1].state = 2;
    D_80081DF8[2].state = 2;
    func_8005A5D0(D_8008C4F0, D_8008C508, 1);
    func_8005A5D0(D_80081DE0, D_8008C510, 80);
    func_800016AC();
    if (osTvType == 2) {
        func_80003C80(D_8008C650, 30, 1);
    } else {
        func_80003C80(D_8008C650, 2, 1);
    }
    func_80003F60(D_8008C650, client, D_80081DE0);
    D_8008F3C0 = func_80003EA8(D_8008C650);
    D_8008F3C4 = func_80003EA0(D_8008C650);
    func_8005C650(64);
    func_80005A20();
    func_80013934();
    func_80048080();
    while (1) {
        func_8001C3F0();
        func_8004E540(D_80081DE0, &msg, 1);
        switch (*msg) {
        case 1:
            start = func_8005B340();
            if (D_800634E4) {
                func_80000B20();
            } else {
                func_80000798();
            }
            D_8008D3B8 = func_8004EF88(func_8004F088(func_8005B340() - start, 1000000), D_8007C990);
            continue;
        case 2:
            func_800128FC(1);
            *(short *)(D_80126BF0 + 0x7C8C2) = func_80003EB0(D_8008C650);
            continue;
        case 3:
            D_800634E4 = 1;
            continue;
        }
        continue;
    }
}
