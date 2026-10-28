typedef struct Channel { int active; unsigned char pad[0xCC]; } Channel;
extern Channel D_8018C980[];
extern void func_8004A050(int index);
extern unsigned short D_80179680[];
extern unsigned char D_8017967E[];
void func_8004A4C0(unsigned short slot) {
    int i;
    for (i = 0; i < 16; i++) {
        if (D_80179680[slot] == D_8018C980[i].active) {
            func_8004A050(i);
        }
    }
    D_80179680[slot] = D_8017967E[slot] = 0;
}
