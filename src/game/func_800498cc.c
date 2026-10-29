typedef struct Entry {
    unsigned char a;
    unsigned char b;
    unsigned char pad[2];
    int c;
} Entry;

typedef struct State {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned char e;
    unsigned char pad5[3];
    int w;
    unsigned short pad0C;
    unsigned short pad0E;
    unsigned char f;
} State;

extern void func_80049E20(void);
extern void func_80049F88(void);
extern void func_80049A78(unsigned short code, unsigned char arg);
extern void func_80049B48();
extern unsigned char D_80179676;
extern unsigned int D_801796F8;
extern unsigned char D_801796D1;
extern unsigned short D_801796FC;
extern unsigned char D_801796FE;
extern State D_80179688;
extern Entry D_800746B0[];

void func_800498CC(void) {
    Entry *entry;
    unsigned short code;

    if (D_80179676) { func_80049E20(); } else { func_80049F88(); }
    code = D_801796F8 & 0x7FFF;
    if (code < 0xC0) {
        if (code < 0x27) {
            if (code != D_801796D1) {
                D_801796FC = code;
                D_801796FE = 4;
            } else {
                func_80049A78(code, 6);
            }
        }
    } else if (code < 0xC1) {
        code -= 0xC0;
        entry = &D_800746B0[code];
        D_80179688.a = entry->a;
        D_80179688.d = entry->b;
        D_80179688.w = entry->c;
        D_80179688.b = 0;
        D_80179688.c = 30;
        D_80179688.e = 6;
        D_80179688.pad0C = 0;
        D_80179688.pad0E = 0;
        D_80179688.f = 0;
        func_80049B48();
    }
}
