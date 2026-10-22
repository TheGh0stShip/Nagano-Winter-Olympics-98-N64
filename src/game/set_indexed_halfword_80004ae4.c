extern unsigned char *D_80126BF0;

void func_80004AE4(short index) {
    *(unsigned short *)(D_80126BF0 + 0x7FB28 + index * 0x78) = 1;
}
