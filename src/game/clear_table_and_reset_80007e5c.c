extern int D_80130C30[];
extern void func_80009AA0(void);
extern void func_80009C90(void);
extern void func_80009DF0(void);
extern void func_8000A094(void);
extern void func_8000A2F0(void);
extern void func_80007F50(void);

void func_80007E5C(void) {
    int *entry = D_80130C30;
    unsigned short i;

    for (i = 0; i < 580; i++, entry++) {
        *entry = 0;
    }
    func_80009AA0();
    func_80009C90();
    func_80009DF0();
    func_8000A094();
    func_8000A2F0();
    func_80007F50();
}
