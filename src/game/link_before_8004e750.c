typedef struct LinkNode {
    struct LinkNode *previous;
    struct LinkNode *next;
} LinkNode;

void func_8004E750(LinkNode *node, LinkNode *next) {
    node->previous = next->previous;
    node->next = next;
    if (next->previous != 0) {
        next->previous->next = node;
    }
    next->previous = node;
}
