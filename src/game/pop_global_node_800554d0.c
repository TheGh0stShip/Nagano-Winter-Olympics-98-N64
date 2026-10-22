typedef struct Node {
    struct Node *next;
} Node;

typedef struct NodeOwner {
    unsigned char pad[0x2C];
    Node *head;
} NodeOwner;

extern NodeOwner *D_8007C910;

Node *func_800554D0(void) {
    Node *result = 0;
    NodeOwner *owner = D_8007C910;
    Node *head = owner->head;

    if (head != 0) {
        result = head;
        owner->head = head->next;
        head->next = 0;
    }
    return result;
}
