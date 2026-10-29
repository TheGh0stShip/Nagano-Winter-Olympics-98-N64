typedef struct Entry {
    int id;
    int value;
} Entry;

typedef struct RuntimeState {
    char pad[0x977F1];
    unsigned char mode;
} RuntimeState;

extern unsigned char D_8006C3EC;
extern unsigned char D_8006C3F0;
extern unsigned char D_80131908;
extern unsigned char D_80063500;
extern signed char D_8006C340;
extern unsigned char D_8006C3D0;
extern signed char D_8006C3F4;
extern int D_80130C30[];
extern RuntimeState *D_80126BF0;
extern Entry D_80131540[];
extern Entry D_80131688[];
extern Entry D_801317C8[];
extern Entry D_80131910;
extern Entry D_80131918;
extern void func_8000C170(void);
extern func_8000C190();

void func_80008270(void) {
    unsigned char i;
    unsigned char j;
    int changed;
    int found;
    Entry *a;
    Entry *b;

    D_80131908 = 0;
    changed = 0;
    if (D_8006C3F0 != D_8006C3EC) {
        changed = 1;
    }
    if (!changed) {
        a = D_80131688;
        i = 0;
        while (i < D_8006C3F0) {
            if (a->id != D_801317C8[i].id || a->value != D_801317C8[i].value) {
                b = D_801317C8;
                found = 0;
                for (j = 0; j < D_8006C3EC; j++, b++) {
                    if (b->id == a->id && b->value == a->value) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    changed = 1;
                    break;
                }
            }
            i++;
            a++;
        }
    }
    if (changed) {
        b = D_801317C8;
        a = D_80131688;
        func_8000C170();
        D_80131908 = 1;
        for (j = 0; j < D_8006C3EC; j++, b++, a++) {
            func_8000C190((void *)b->value);
            a->id = b->id;
            a->value = b->value;
            D_80130C30[b->id] = b->value;
        }
        D_8006C3F0 = D_8006C3EC;
    }
}

void func_8000840C(void) {
    unsigned char i;
    signed char v;

    if (D_8006C340 != 0 && D_80131908 == 0) {
        if (D_80063500 != 0 || D_80126BF0->mode == 2) {
            D_80131910 = D_80131540[0];
            func_8000C190(&D_80131910);
            if (D_8006C340 >= 2) {
                D_80131918 = D_80131540[1];
                func_8000C190(&D_80131918);
            }
            for (i = 2; i < D_8006C340; i++) {
                D_80131540[i - 2] = D_80131540[i];
            }
            D_8006C340 -= 2;
            if (D_8006C340 < 0) {
                D_8006C340 = 0;
            }
        } else if (D_8006C3D0 == 0 && (v = D_8006C3F4) > 0) {
            v--;
            D_8006C3F4 = v;
        } else {
            D_80131910 = D_80131540[0];
            func_8000C190(&D_80131910);
            for (i = 1; i < D_8006C340; i++) {
                D_80131540[i - 1] = D_80131540[i];
            }
            D_8006C340 -= 1;
            if (D_8006C340 < 0) {
                D_8006C340 = 0;
                D_8006C3F4 = v = (v & 0) | 5;
            } else {
                D_8006C3D0 = 1;
            }
        }
    }
}
