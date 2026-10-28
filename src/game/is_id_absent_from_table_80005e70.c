extern unsigned char *D_80126BF0;

int func_80005E70(int value) {
    int *entry = (int *)(D_80126BF0 + 0x9673C);
    unsigned char i;

    for (i = 0; i < 40; i++, entry++) {
        if (*entry == value) {
            return 0;
        }
    }
    return 1;
}
