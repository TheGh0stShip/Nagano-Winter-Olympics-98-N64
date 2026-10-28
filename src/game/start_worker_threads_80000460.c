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
