typedef struct Menu {
    unsigned char pad[0x180];
    unsigned char slots[16];
} Menu;

extern Menu *D_80138210;

int func_80038E0C(int value) {
    int i;

    value++;
    for (i = 0; i < 16; i++) {
        if (D_80138210->slots[i] == value) {
            return i;
        }
    }
    return -1;
}
