typedef struct Node {
    struct Node *next;
    struct Node *link;
    unsigned int pad8;
    unsigned int age;
} Node;

typedef struct List {
    unsigned int pad0;
    Node *head;
    Node *tail;
} List;

extern unsigned int D_80073684;
extern unsigned int D_80073680;
extern unsigned char D_8013D510[];
extern List D_8013CB08;
extern void func_8004E540(void *a, void *b, int c);
extern void func_8004E720(Node *n);
extern void func_8004E750(Node *n, Node *t);

void func_80047F60(void) {
    unsigned int i;
    unsigned int out;
    unsigned int pad;
    Node *node;
    Node *next;

    for (i = 0; i < D_80073684; i++) {
        func_8004E540(D_8013D510, &out, 0);
    }
    for (node = D_8013CB08.head; node != 0; node = next) {
        next = node->next;
        if (node->age + 0xF < D_80073680) {
            if (D_8013CB08.head == node) {
                D_8013CB08.head = node->next;
            }
            func_8004E720(node);
            if (D_8013CB08.tail != 0) {
                func_8004E750(node, D_8013CB08.tail);
            } else {
                D_8013CB08.tail = node;
                node->next = 0;
                node->link = 0;
            }
        }
    }
    D_80073680 = D_80073680 + 1;
    D_80073684 = 0;
}
