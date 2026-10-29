#define Heap HeapA
#define Block BlockA
typedef struct Block { char *start; unsigned int size; struct Block *next; struct Block *prev; } Block;
typedef struct { char *base; unsigned int size; Block *list; } Heap;
char *func_800038A0(Heap *h, int size) {
    char *base;
    unsigned int hsize;
    Block *prev;
    Block *last;
    Block *b;
    char *p;
    char *q;
    unsigned int need;
    base = h->base;
    hsize = h->size;
    p = base;
    prev = 0;
    b = h->list;
    last = 0;
    while (b != 0) {
        last = b;
        if ((unsigned int)(b->start - p) >= ((unsigned int)(size + 0x4F) >> 6 << 6)) break;
        prev = b;
        p = (char *)(b + 1);
        b = b->next;
    }
    need = (unsigned int)(size + 0x4F) >> 6 << 6;
    if (b == 0) {
        b = (Block *)(p + need - 0x10);
        if (h->list != 0) {
            p = (char *)(prev + 1);
        } else {
            p = base;
        }
        if ((unsigned int)(base + hsize - p) < need) {
            return 0;
        }
        b->start = p;
        b->size = need;
    } else {
        b = (Block *)(p + need) - 1;
        b->start = p;
        b->size = need;
        last->prev = b;
    }
    if (prev == 0) {
        b->next = h->list;
        b->prev = 0;
        h->list = b;
    } else {
        b->next = prev->next;
        b->prev = prev;
        prev->next = b;
    }
    for (q = p; q < (char *)b; q++) { *q = 0; }
    return b->start;
}
#undef Heap
#undef Block
#define Heap HeapB
#define Node NodeB
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
#undef Heap
#undef Node
#undef HEAP_ALLOC_SIZE
typedef struct Node {
    char *data;
    unsigned int size;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Pool {
    int pad0;
    int pad4;
    Node *head;
} Pool;

void *func_80003B1C(Pool *pool, void *ptr) {
    Node *n;
    Node *prev;
    Node *next;
    char *p;
    unsigned int size;

    n = pool->head;
    while (n != 0) {
        if (n->data == ptr) break;
        n = n->next;
    }
    if (n == 0) {
        return 0;
    }
    prev = n->prev;
    next = n->next;
    if (n == pool->head) {
        pool->head = next;
    } else {
        prev->next = next;
    }
    if (next != 0) {
        next->prev = prev;
    }
    p = n->data;
    size = n->size;
    while (size--) { *p++ = 0; }
    return ptr;
}
