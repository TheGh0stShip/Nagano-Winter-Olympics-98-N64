typedef struct Rec {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x51];
    unsigned short word58;
    unsigned char pad5A[0x4C];
    signed char offsetA6;
    unsigned char padA7[0x1B];
    short bendC2;
} Rec;

typedef struct Slot {
    unsigned char data[28];
} Slot;

extern Rec *D_80179924;
extern unsigned char D_80179670;
extern Slot D_80179760[];
extern void *D_8007C910;
extern void func_800542F0(void *p, void *q, unsigned char v);

void func_8004A250(unsigned char index) {
    short v;
    Rec *r = D_80179924;

    r->flags |= 1;
    if (D_80179670) {
        v = 0x40;
    } else {
        r = D_80179924;
        v = (r->word58 >> 8) & 0x7F;
        v += r->offsetA6;
        if (r->bendC2 != 0) {
            v += r->bendC2 / 256;
        }
        if (v < 0) {
            v = 0;
        } else if (v >= 0x80) {
            v = 0x7F;
        }
    }
    func_800542F0(D_8007C910, &D_80179760[index], v);
}
