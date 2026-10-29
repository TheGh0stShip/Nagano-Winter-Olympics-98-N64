typedef struct {
    char pad[0x14];
    unsigned short s14;
    char pad16[0x12];
    long long val;
    short s30;
} Disp;

void func_80036F18(Disp *d) {
    d->s30 = 0;
    if (d->val >= 0) {
        d->s30 = 1;
    }
}
