typedef struct Entry {
    int id;
    int value;
} Entry;

extern unsigned char D_8006C3EC;
extern unsigned char D_8006C3F0;
extern unsigned char D_80131908;
extern int D_80130C30[];
extern Entry D_80131688[];
extern Entry D_801317C8[];
extern void func_8000C170(void);
extern void func_8000C190(int);

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
            func_8000C190(b->value);
            a->id = b->id;
            a->value = b->value;
            D_80130C30[b->id] = b->value;
        }
        D_8006C3F0 = D_8006C3EC;
    }
}
