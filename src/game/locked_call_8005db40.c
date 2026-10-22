extern void func_80050540(void);
extern int func_8005DB80(int, int);
extern void func_80050584(void);

int func_8005DB40(int first, int second) {
    register int result;

    func_80050540();
    result = func_8005DB80(first, second);
    func_80050584();
    return result;
}
