typedef struct Ent {
    int flags;
    unsigned char pad4[0xB4];
    short tgt[3];
    short cur[3];
    short delta[3];
    unsigned char steps[3];
    unsigned char padCD[3];
} Ent;

typedef struct Cfg {
    unsigned char pad0[3];
    unsigned char steps;
    short tgt;
} Cfg;

extern Ent *D_80179924;
extern unsigned char D_80179930;
extern Cfg D_80179938[];
extern Ent D_8018C980[16];

void func_8004932C(int idx, int id) {
    unsigned char steps;
    short tgt;
    int i;
    int diff;

    steps = D_80179938[D_80179930].steps;
    tgt = D_80179938[D_80179930].tgt;
    for (i = 0; i < 16; i++) {
        D_80179924 = &D_8018C980[i];
        if (id == (D_80179924->flags & 0x7FFF)) {
            if (tgt != D_80179924->cur[idx]) {
                diff = tgt - D_80179924->cur[idx];
                diff /= steps;
                D_80179924->steps[idx] = steps;
                D_80179924->tgt[idx] = tgt;
                D_80179924->delta[idx] = diff;
            }
        }
    }
}
