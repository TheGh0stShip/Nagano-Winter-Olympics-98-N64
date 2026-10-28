extern void func_80005CAC(void);
extern unsigned short func_80005C48(void);
extern unsigned short func_80005D74(void);
extern unsigned short func_80005D10(void);

void func_800104F8(short *selection) {
    short unused;
    unsigned short first;
    unsigned short second;

    func_80005CAC();
    first = func_80005C48();
    second = func_80005D74();
    func_80005D10();
    if ((first & 0x400) || (second & 0x400)) {
        (*selection)++;
        if (*selection >= 5) {
            *selection -= 5;
        }
    }
    if ((first & 0x800) || (second & 0x800)) {
        (*selection)--;
        if (*selection < 0) {
            *selection += 5;
        }
    }
}
