typedef struct GlobalLink {
    struct GlobalLink *next;
} GlobalLink;

typedef struct GlobalLinkOwner {
    unsigned char pad[0x2C];
    GlobalLink *head;
} GlobalLinkOwner;

extern GlobalLinkOwner *D_8007C910;

void func_800554B8(GlobalLink *node) {
    GlobalLinkOwner *owner = D_8007C910;
    node->next = owner->head;
    owner->head = node;
}
