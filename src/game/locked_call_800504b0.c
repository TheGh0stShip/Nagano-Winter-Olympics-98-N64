extern void func_80050540(void);
extern int func_800505B0(int, int);
extern void func_80050584(void);

int func_800504B0(int first, int second) {
    register int result;

    func_80050540();
    result = func_800505B0(first, second);
    func_80050584();
    return result;
}
