extern int D_8007C960;
extern unsigned char D_801929D8[];
extern void func_800504F0(void);
extern void func_8004E540(void *, void *, int);

void func_80050540(void) {
    int state;
    if (D_8007C960 == 0) {
        func_800504F0();
    }
    func_8004E540(D_801929D8, &state, 1);
}
