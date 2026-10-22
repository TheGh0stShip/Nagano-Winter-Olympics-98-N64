extern unsigned char D_80130BE0[];
extern void func_80059620(void *);
extern void func_8004E540(void *, int, int);
extern void func_800596A4(void *);

void func_800138F0(void *object) {
    func_80059620(D_80130BE0);
    func_8004E540(D_80130BE0, 0, 1);
    func_800596A4(object);
}
