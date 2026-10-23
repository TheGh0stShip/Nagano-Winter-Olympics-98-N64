extern unsigned char *D_80126BF0;

unsigned int func_80005DE0(unsigned int index, unsigned int value) {
    return *(unsigned int *)(D_80126BF0 + 0x7C92C + index * 4) +
           (value & 0xF0FFFFFF);
}
