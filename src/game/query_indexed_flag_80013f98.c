extern unsigned char D_80135370[];
extern void func_800138F0(void *);

int func_80013F98(unsigned char index) {
    func_800138F0(D_80135370);
    if ((D_80135370[2 + index * 4] & 1) != 0) {
        return 2;
    }
    return 1;
}
