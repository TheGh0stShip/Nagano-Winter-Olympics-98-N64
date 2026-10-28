typedef struct Slot {
    unsigned short state;
    unsigned char pad[0xC];
} Slot;

extern unsigned char *D_80126BF0;

int func_8000DA60(void) {
    unsigned short i;

    for (i = 0; i < 4; i++) {
        if (((Slot *)(D_80126BF0 + 0x7C8F4))[i].state == 1) {
            return 0;
        }
    }
    return 1;
}
