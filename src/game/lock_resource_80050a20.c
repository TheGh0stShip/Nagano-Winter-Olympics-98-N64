extern int D_8007C980;
extern unsigned char D_80192A88[];
extern void func_800509D0(void);
extern void func_8004E540(void *, void *, int);

void func_80050A20(void) {
    int state;
    if (D_8007C980 == 0) {
        func_800509D0();
    }
    func_8004E540(D_80192A88, &state, 1);
}
