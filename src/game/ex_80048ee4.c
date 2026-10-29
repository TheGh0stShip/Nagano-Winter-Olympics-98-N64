typedef struct QueueEntry {
    unsigned short value;
    unsigned char kind;
    unsigned char pad[3];
} QueueEntry;

extern unsigned char D_80179930;
extern QueueEntry D_80179938[];
extern unsigned int D_801796F8;
extern void (*D_800737B0[])(void);
extern void func_800498CC(void);
extern void func_80049470(int);
extern void func_80049020(int);
extern void func_8004932C(int);

void func_80048EE4(void) {
    QueueEntry *entry;
    unsigned short value;

    while (D_80179930 != 0) {
        D_80179930--;
        entry = &D_80179938[D_80179930];
        value = entry->value;
        switch (entry->kind) {
        case 0:
            D_801796F8 = value;
            if (value < 0x100U) {
                if (value < 0x10U) {
                    D_800737B0[value - 1]();
                } else {
                    func_800498CC();
                }
            } else {
                func_80049470(0);
            }
            break;
        case 1:
            func_80049020(value);
            break;
        case 2:
            func_8004932C(0);
            break;
        case 3:
            func_8004932C(1);
            break;
        case 4:
            func_8004932C(2);
            break;
        }
    }
}
