typedef struct LinkRecord {
    struct LinkRecord *next;
    int value;
} LinkRecord;

typedef struct LinkOwner {
    unsigned char padding[0xD28];
    LinkRecord *head;
} LinkOwner;

extern unsigned int func_8004E680(int mode);

void func_80003F60(LinkOwner *owner, LinkRecord *record, int value) {
    unsigned int lock = func_8004E680(1);

    record->value = value;
    record->next = owner->head;
    owner->head = record;
    func_8004E680(lock);
}
