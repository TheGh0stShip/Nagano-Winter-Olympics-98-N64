typedef struct Obj {
    unsigned int flags;
    unsigned char pad[0xCC];
} Obj;

extern signed char D_8017966E;
extern signed char D_8017966F;
extern unsigned char D_80179673;
extern unsigned short D_80179678;
extern unsigned char D_8017967A;
extern unsigned char D_8017967B;
extern unsigned char D_8017967C;
extern short D_801796FC;
extern signed char D_801796FE;
extern Obj D_8018C980[];
extern void func_8004A050(int);

void func_80049F88(void) {
    int i;
    unsigned int v;

    D_801796FC = 0;
    D_801796FE = 0;
    D_80179673 = D_8017967A = D_80179678 = 0;
    D_8017967B = D_8017967C = 0;
    for (i = 0; i < 16; i++) {
        v = D_8018C980[i].flags & 0x7FFF;
        if (v >= 0x10 && v < 0x100) {
            func_8004A050(i);
        }
    }
    D_8017966F = D_8017966E = 0;
}
