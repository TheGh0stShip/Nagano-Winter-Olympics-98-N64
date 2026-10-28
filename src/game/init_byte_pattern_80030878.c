extern unsigned char D_80137566[];

void func_80030878(void) {
    unsigned char *entry = D_80137566;
    unsigned short i;

    for (i = 0; i < 64; i++, entry++) {
        if (i % 4 == 3) {
            *entry = 0x5F;
        } else {
            *entry = 0;
        }
    }
}
