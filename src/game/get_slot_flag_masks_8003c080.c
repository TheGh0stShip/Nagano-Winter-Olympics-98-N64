typedef struct Slot {
    unsigned short state;
    unsigned short first;
    unsigned short second;
    unsigned short pad6[2];
    unsigned short firstMask;
    unsigned short secondMask;
} Slot;

extern unsigned char *D_80126BF0;

void func_8003C080(int index, unsigned short *first, unsigned short *second) {
    *first = 0;
    *second = 0;
    if (((Slot *)(D_80126BF0 + 0x7C8F4))[index].state != 0) {
        *first = ((Slot *)(D_80126BF0 + 0x7C8F4))[index].first |
                 ((Slot *)(D_80126BF0 + 0x7C8F4))[index].firstMask;
        *second = ((Slot *)(D_80126BF0 + 0x7C8F4))[index].second |
                  ((Slot *)(D_80126BF0 + 0x7C8F4))[index].secondMask;
    }
}
