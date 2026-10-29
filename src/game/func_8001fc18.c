typedef struct {
    unsigned short s[7];
} Entry;
typedef struct {
    char pad0[0x7C8F4];
    Entry e[(0x977EF - 0x7C8F4) / 14];
    char pad1[0x977EF - 0x7C8F4 - ((0x977EF - 0x7C8F4) / 14) * 14];
    unsigned char idx;
} Big;
extern Big *D_80126BF0;
typedef struct {
    char pad0[3];
    signed char timer;
    signed char rate;
    char pad5;
    unsigned short last;
} Rep;
extern double D_8007EE38;
extern double D_8007EE40;

unsigned short func_8001FC18(void) {
    static Rep D_80136900;
    Big *p;
    unsigned short a;
    unsigned short b;
    signed char r;

    p = D_80126BF0;
    if (p->e[p->idx].s[0] == 1) {
        a = (p->e[p->idx].s[1] | p->e[p->idx].s[5]) & 0xF00;
        b = (p->e[p->idx].s[2] | p->e[p->idx].s[6]) & 0xF00;
        if (b) {
            if (D_80136900.timer) {}
            D_80136900.rate = (D_80136900.rate & 0) | 8;
            D_80136900.timer = D_80136900.rate * D_8007EE38;
            D_80136900.last = b;
            return b;
        }
        if (a == D_80136900.last) {
            if (--D_80136900.timer < 0) {
                D_80136900.timer = D_80136900.rate * D_8007EE40;
                if (--D_80136900.rate < 2) {
                    D_80136900.rate = 2;
                }
                return a;
            }
            return 0;
        }
        D_80136900.last = a;
        D_80136900.timer = 0;
        return a;
    }
}
