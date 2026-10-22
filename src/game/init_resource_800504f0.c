extern int D_8007C960;
extern unsigned char D_801929D0[];
extern unsigned char D_801929D8[];
extern void func_8005A5D0(void *, void *, int);
extern void func_8004E2A0(void *, int, int);

void func_800504F0(void) {
    D_8007C960 = 1;
    func_8005A5D0(D_801929D8, D_801929D0, 1);
    func_8004E2A0(D_801929D8, 0, 0);
}
