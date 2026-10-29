typedef struct Ent49 {
    unsigned char b0;
    unsigned char b1;
    unsigned char pad2[2];
    int w;
} Ent49;

typedef struct Slot {
    int id;
    unsigned char f4;
    unsigned char pad5[0xCB];
} Slot;

typedef struct Snd {
    unsigned char active;
    unsigned char slot;
    unsigned char lvl;
    unsigned char b3;
    unsigned char b4;
    unsigned char pad5[3];
    int *p;
    short c;
    short e;
    unsigned char g;
} Snd;

extern Ent49 *D_800736BC[];
extern Slot D_8018C980[];
extern Snd D_80179688;
extern int D_801796F8;
extern unsigned char D_8017975A;
extern int D_80179700;
extern unsigned char func_800497C4(unsigned char);
extern void func_80049B48(void);

void func_80049470(int arg0) {
    unsigned short v = D_801796F8 & 0x7FFF;
    
    Ent49 *row;
    unsigned char slot;
    int i;
    int found;
    unsigned char lvl;
    unsigned char act;

    switch (D_8018C980[0].id & 0x7FFF) {
        case 0x15:
        case 0x16:
        case 0x1C:
        case 0x23:
        case 0x24:
        case 0x25:
            if (v != 0x3F0 && v != 0x3F1 && v != 0x3F2 && v != 0x3F3) {
                return;
            }
            break;
    }
    if (v >= 0x300 && v < 0x468) {
        D_8017975A = 2;
    }
    if (v >= 0x200) {
        if (v >= 0x4BD) {
            return;
        }
        row = D_800736BC[v >> 8];
        D_80179688.lvl = row[v & 0xFF].b0;
        D_80179688.lvl &= 0x1F;
        slot = row[v & 0xFF].b1;
        D_80179688.b3 = slot & 0xF;
        slot = slot >> 4;
        found = slot;
        if (found == 0) {
            for (i = 8; i < 16; i++) {
                if ((unsigned)(int)v == (D_8018C980[i].id & 0x7FFF)) {
                    slot = i;
                    break;
                }
            }
            found = slot;
            if (found == 0) {
                slot = func_800497C4(1);
            }
        }
        if (arg0) {
            if (D_8018C980[slot].f4 >= D_80179688.lvl) {
                return;
            }
        } else if (D_80179688.lvl < D_8018C980[slot].f4) {
            return;
        }
        D_80179688.slot = slot;
        D_80179688.active = 1;
        D_80179688.p = &D_80179700;
        D_80179700 = row[v & 0xFF].w;
    } else {
        if (v >= 0x156) {
            return;
        }
        row = D_800736BC[v >> 8];
        slot = row[v & 0xFF].b0;
        D_80179688.lvl = slot & 0x1F;
        D_80179688.active = (slot >> 5) + 1;
        slot = row[v & 0xFF].b1;
        D_80179688.b3 = slot & 0xF;
        slot = slot >> 4;
        if (D_80179688.active == 2) {
            found = slot;
            if (found == 0) {
                for (i = 14; i != 6; i -= 2) {
                    if ((unsigned)(int)v == (D_8018C980[i].id & 0x7FFF)) {
                        slot = i;
                        break;
                    }
                }
                found = slot;
                if (found == 0) {
                    slot = func_800497C4(2);
                }
            }
            if (D_80179688.lvl < D_8018C980[slot].f4) {
                return;
            }
            if (D_80179688.lvl < D_8018C980[slot + 1].f4) {
                return;
            }
        }
        D_80179688.slot = slot;
        D_80179688.p = (int *)row[v & 0xFF].w;
    }
    D_80179688.b4 = 6;
    if (arg0 == 0) {
        D_80179688.c = 0;
        D_80179688.e = 0;
        D_80179688.g = 0;
    }
    func_80049B48();
}
