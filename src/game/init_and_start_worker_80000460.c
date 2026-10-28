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
