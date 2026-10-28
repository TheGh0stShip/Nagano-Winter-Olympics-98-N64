extern unsigned int func_80054020(void *address);

unsigned int func_800512C0(void *address) {
    if ((unsigned int)address >= 0x80000000 && (unsigned int)address < 0xA0000000) {
        return (unsigned int)address & 0x1FFFFFFF;
    } else if ((unsigned int)address >= 0xA0000000 && (unsigned int)address < 0xC0000000) {
        return (unsigned int)address & 0x1FFFFFFF;
    } else {
        return func_80054020(address);
    }
}
