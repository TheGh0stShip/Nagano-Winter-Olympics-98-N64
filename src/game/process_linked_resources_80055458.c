typedef struct ResourceList {
    unsigned char pad[4];
    unsigned char anchor[0x10];
    void *head;
} ResourceList;

extern void func_8004E720(void *);
extern void func_8004E750(void *, void *);

void func_80055458(ResourceList *list) {
    void *node = list->head;
    while (node != 0) {
        func_8004E720(node);
        func_8004E750(node, list->anchor);
        node = list->head;
    }
}
