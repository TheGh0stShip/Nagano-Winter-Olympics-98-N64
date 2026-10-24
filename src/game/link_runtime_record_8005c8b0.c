typedef struct RuntimeList {
    void *head;
    unsigned char pad4[0x1C];
    void *tail;
} RuntimeList;

typedef struct RuntimeRecord {
    void *head;
    unsigned char pad4[0xC];
    void *tail;
} RuntimeRecord;

extern int func_8004E680(int);

void func_8005C8B0(RuntimeList *list, RuntimeRecord *record) {
    int state = func_8004E680(1);

    record->tail = list->tail;
    record->head = list->head;
    list->head = record;
    func_8004E680(state);
}
