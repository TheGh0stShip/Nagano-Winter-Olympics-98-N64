typedef struct Entry {
    int id;
    int value;
} Entry;

extern unsigned char D_8006C3EC;
extern unsigned char D_8006C3F0;
extern Entry D_80131688[];
extern Entry D_801317C8[];
extern void func_8000C190(int);

void func_800080D4(void) {
    unsigned char i;
    unsigned char j;
    int changed;
    int found;
    Entry *a;
    Entry *b;

    changed = 0;
    if (D_8006C3F0 != D_8006C3EC) {
        changed = 1;
    }
    if (!changed) {
        a = D_80131688;
        i = 0;
        while (i < D_8006C3F0) {
            b = D_801317C8;
            found = 0;
            if (a->id != D_801317C8[i].id) {
                for (j = 0; j < D_8006C3EC; j++, b++) {
                    if (b->id == a->id) {
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
        for (i = 0; i < D_8006C3EC; i++, b++) {
            a = &D_80131688[i];
            if (b->id != a->id) {
                a = D_80131688;
                found = 0;
                for (j = 0; j < D_8006C3F0; j++, a++) {
                    if (b->id == a->id) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    func_8000C190(b->value);
                    D_80131688[D_8006C3F0] = *b;
                    D_8006C3F0++;
                }
            }
        }
    }
}
