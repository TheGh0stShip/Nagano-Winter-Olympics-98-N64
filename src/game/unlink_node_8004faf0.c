typedef struct LinkedNode {
    struct LinkedNode *next;
} LinkedNode;

void func_8004FAF0(LinkedNode **head, LinkedNode *target) {
    register LinkedNode **link = head;
    register LinkedNode *node = *link;

    while (node != 0) {
        if (node == target) {
            *link = target->next;
            break;
        }
        link = &node->next;
        node = *link;
    }
}
