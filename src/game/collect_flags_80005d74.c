extern char *D_80126BF0;

unsigned short func_80005D74(void) {
    unsigned short flags = 0;
    short i;

    for (i = 0; i < 4; i++) {
        if (*(unsigned short *)(D_80126BF0 + 0x78000 + i * 14 + 0x48F4) != 0) {
            flags |= *(unsigned short *)(D_80126BF0 + 0x78000 + i * 14 + 0x4900);
        }
    }
    return flags;
}
