typedef struct RecA { unsigned char b[0x428]; } RecA;
typedef struct RecB { unsigned char b[0x150]; } RecB;
typedef struct RecC { unsigned char b[0x148]; } RecC;
typedef struct RecD { unsigned char b[0x138]; } RecD;

extern unsigned char *D_80126BF0;
extern void func_800301A0(void *cells);

void func_80030214(void) {
    short i;
    RecA *a = (RecA *)(D_80126BF0 + 0x802A8);
    RecB *b = (RecB *)(D_80126BF0 + 0x83868);
    RecC *c = (RecC *)(D_80126BF0 + 0x8B2C0);
    RecD *d = (RecD *)(D_80126BF0 + 0x83EF8);

    for (i = 0; i < 10; i++) {
        func_800301A0(a->b + 0x38);
        a++;
    }
    for (i = 0; i < 5; i++) {
        func_800301A0(b->b + 0x38);
        b++;
    }
    for (i = 0; i < 0x58; i++) {
        func_800301A0(c->b + 0x38);
        c++;
    }
    for (i = 0; i < 0x5F; i++) {
        func_800301A0(d->b + 0x38);
        d++;
    }
}
