extern void *func_80005DE0(void *segments, unsigned int address);

void *func_80005E18(void *segments, unsigned int address) {
    if (address >= 0x80000001U) {
        return (void *)address;
    }
    if (address >= 0x06000000U) {
        return func_80005DE0(segments, address);
    }
    return (void *)(address + 0x80000000U);
}
