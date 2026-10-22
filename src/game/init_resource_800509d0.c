extern int D_8007C980;
extern unsigned char D_80192A80[];
extern unsigned char D_80192A88[];
extern void func_8005A5D0(void *, void *, int);
extern void func_8004E2A0(void *, int, int);

void func_800509D0(void) {
    D_8007C980 = 1;
    func_8005A5D0(D_80192A88, D_80192A80, 1);
    func_8004E2A0(D_80192A88, 0, 0);
}
