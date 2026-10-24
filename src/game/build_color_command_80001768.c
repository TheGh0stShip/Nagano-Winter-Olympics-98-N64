extern void func_80051340(unsigned int *, int);

void func_80001768(unsigned int *command, unsigned int value) {
    command[0] = 0x3C190000 + ((value >> 16) & 0xFFFF);
    command[1] = 0x27390000 + (value & 0xFFFF);
    command[2] = 0x03200008;
    command[3] = 0;
    func_80051340(command, 16);
}
