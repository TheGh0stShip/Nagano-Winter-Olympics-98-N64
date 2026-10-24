typedef struct StreamRecord {
    unsigned char pad0[0x0E];
    unsigned char notify;
    unsigned char notified;
    unsigned char pad10[0x11];
    unsigned char value;
    unsigned char active;
} StreamRecord;

extern void *D_8007C910;
extern unsigned char D_8017966C;
extern unsigned char D_80179760[];
extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;

extern void func_8004EB90(void *context, unsigned char *entry, int arg2,
                          int duration);

void func_8004D244(void) {
    if (D_80179924->notify != 0) {
        D_80179924->notified = 1;
        func_8004EB90(D_8007C910, &D_80179760[D_8017966C * 28], 0, 5000);
    }
    D_80179924->value = *D_80179920;
    D_80179920++;
    D_80179924->active = 1;
}
