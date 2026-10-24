extern int func_80007170(int mode);
extern void func_8000FCA8(void);
extern void func_8000FD44(void);
extern void func_8000FCF4(void);

int func_8000FDB0(void) {
    if (func_80007170(0x1B) == 0) {
        return 0;
    }

    func_8000FCA8();
    func_8000FD44();
    func_8000FCF4();
    return 1;
}
