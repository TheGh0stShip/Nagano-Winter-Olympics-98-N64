typedef struct LinkNode {
    struct LinkNode *next;
    void *value;
} LinkNode;

typedef struct LinkOwner {
    unsigned char pad[0xD28];
    LinkNode *head;
} LinkOwner;

extern void func_8004E2A0(void *, int, int);

void func_80004038(LinkOwner *owner, int value) {
    LinkNode *node = owner->head;

    while (node != 0) {
        func_8004E2A0(node->value, value, 0);
        node = node->next;
    }
}
