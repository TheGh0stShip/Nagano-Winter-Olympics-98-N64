typedef struct Node8004E720 {
    struct Node8004E720 *previous;
    struct Node8004E720 *next;
} Node8004E720;
void func_8004E720(Node8004E720 *node) {
    if (node->previous != 0) {
        node->previous->next = node->next;
    }
    if (node->next != 0) {
        node->next->previous = node->previous;
    }
}
