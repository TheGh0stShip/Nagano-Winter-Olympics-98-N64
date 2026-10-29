typedef struct Node {
    int pad0;
    float f4;
    float f8;
    float fC;
    short pad10;
    unsigned short idx;
    unsigned short flags;
    int w18;
    int w1C;
    struct Node *next;
    int pad24;
    double d28;
    unsigned short w30;
} Node;

typedef struct Slot {
    char pad[0x128];
    int w128;
    int w12C;
} Slot;

extern unsigned char *D_80126BF0;
extern int D_80072AEC;
extern unsigned char D_80137DF5;
extern int func_8003EB14(int);
extern void func_8003EAE0(int, int);
extern void func_800389B4(int);
extern void func_80038930(int);
extern int func_80038FC4(void);
extern void func_80039004(int, float, float, int, int, int);
extern void func_8003EAA8(int, int);
extern void func_8003EB48(int, int);
extern void func_8003EC10(int, float, float, int);
extern void func_8003EB80(int, int);
extern void func_8003839C(int, double);

void func_800377E8(Node *n, float dx, float dy) {
    int idx;
    Slot *slot;

    idx = n->idx;
    slot = (Slot *)(D_80126BF0 + 0x8B2C0 + idx * 0x148);
    if (n->next != 0) {
        func_800377E8(n->next, dx, dy);
    }
    if (idx >= 0) {
        if (func_8003EB14(idx) == 0) {
            func_8003EAE0(idx, 2);
        }
        if (func_8003EB14(idx) == 2) {
            if (n->flags != 0) {
                func_800389B4(idx);
            } else if (D_80072AEC == n->w18) {
                func_80038930(idx);
                slot->w128 = n->w18;
                slot->w12C = n->w1C;
            } else {
                func_80039004(idx, n->f8 + dx, n->fC + dy, n->w18, n->w1C, func_80038FC4());
            }
            func_8003EAE0(idx, 2);
            func_8003EAA8(idx, n->flags);
            func_8003EB48(idx, *(int *)&n->f4);
            func_8003EC10(idx, n->f8 + dx, n->fC + dy, D_80137DF5);
            func_8003EB80(idx, n->w30);
            if (!(n->flags & 0x800)) {
                func_8003839C((int)n->f4, n->d28);
            }
        }
    }
}
