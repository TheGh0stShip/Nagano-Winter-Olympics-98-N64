typedef struct Node {
    unsigned char *data;
    unsigned int size;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Heap {
    unsigned char *base;
    unsigned int size;
    Node *head;
} Heap;

#define HEAP_ALLOC_SIZE(n) (((n) + sizeof(Node) + 0x3F) / 0x40 * 0x40)

unsigned char *func_800039D4(Heap *heap, unsigned int size) {
    unsigned char *base = heap->base;
    unsigned int total = heap->size;
    unsigned char *start = base;
    Node *prev = 0;
    Node *node;
    Node *entry;
    unsigned char *p;
    unsigned int alloc;

    for (entry = heap->head; entry != 0; entry = entry->next) {
        prev = entry;
        start = (unsigned char *)(entry + 1);
    }
    alloc = HEAP_ALLOC_SIZE(size);
    if ((unsigned int)base + total - (unsigned int)start >= alloc) {
        entry = (Node *)(base + total) - 1;
        start = base + total - alloc;
        entry->data = start;
        entry->size = alloc;
    } else {
        if (prev == 0) {
            return 0;
        }
        for (node = prev; node != 0; node = prev) {
            prev = node->prev;
            if (prev == 0) {
                start = base;
            } else {
                start = (unsigned char *)(prev + 1);
            }
            if ((unsigned int)(node->data - start) >= alloc) {
                break;
            }
        }
        if (node == 0) {
            return 0;
        }
        entry = (Node *)node->data - 1;
        start = node->data - alloc;
        entry->data = start;
        entry->size = alloc;
        node->prev = entry;
    }
    if (prev == 0) {
        entry->next = heap->head;
        entry->prev = 0;
        heap->head = entry;
    } else {
        entry->next = prev->next;
        entry->prev = prev;
        prev->next = entry;
    }
    p = start;
    if (p < (unsigned char *)entry) {
        do {
            *p++ = 0;
        } while (p < (unsigned char *)entry);
    }
    return entry->data;
}
