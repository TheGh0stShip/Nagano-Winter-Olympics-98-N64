typedef struct Request {
    unsigned short id;
    short value;
    unsigned char kind;
    unsigned char pad5;
} Request;

extern unsigned char D_801796D0;
extern Request D_801796A0[];
extern unsigned char D_80179669;

void func_8004872C(unsigned short id, unsigned char kind, short value) {
    if (D_801796D0 < 8 && id != 0 && kind < 3) {
        D_801796A0[D_801796D0].id = id;
        D_801796A0[D_801796D0].value = value;
        D_801796A0[D_801796D0].kind = kind;
        D_801796D0++;
        D_80179669 = 0;
    }
}
