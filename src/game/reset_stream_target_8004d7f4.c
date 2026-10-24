typedef struct StreamTarget {
    int state;
    unsigned char state_byte;
    unsigned char pad5[9];
    unsigned char enabled;
    unsigned char initialized;
} StreamTarget;

extern StreamTarget *D_80179924;
extern unsigned char D_8017966C;
extern unsigned char D_80179760[][0x1C];
extern void *D_8007C910;

extern void func_8004EB90(void *, void *, int, int);

void func_8004D7F4(void) {
    if (D_80179924->enabled != 0) {
        D_80179924->initialized = 1;
        func_8004EB90(D_8007C910, D_80179760[D_8017966C], 0, 5000);
    }
    D_80179924->state = 0;
    D_80179924->state_byte = D_80179924->state;
}
