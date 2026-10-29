typedef struct { char pad[0x18]; unsigned short type; char pad2[6]; int active; char pad3[0xC]; } Ent;
typedef struct { int idx[5]; int a; int b; int c; } Out;
extern unsigned char *D_80126BF0;
extern Ent *D_8006C240[];
int func_80036740(Out *arg0) {
    int n;
    Ent *e;
    int i;
    Ent *tmp;
    unsigned short t;
    n = 0;
    tmp = D_8006C240[D_80126BF0[0x977EC]];
    if (tmp == 0) {
        return -1;
    }
    for (i = 0, e = tmp; ; e++, i++) {
        t = e->type;
        if (e->active == 0) break;
        if (t == 1) {
            arg0->a = i;
        } else if (t == 2) {
            arg0->b = i;
        } else if (t == 3) {
            arg0->c = i;
        } else if ((t & 0xC00) && (n < 5)) {
            arg0->idx[n] = i;
            n++;
        }
    }
    return n;
}
