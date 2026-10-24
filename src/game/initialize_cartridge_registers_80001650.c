extern void func_8005DB40(unsigned int address, unsigned int value);

void func_80001650(void) {
    if (*(volatile unsigned int *)0xBFF00000 != 0x4B4D4300) {
        func_8005DB40(0xB1FF0014, 0);
        func_8005DB40(0xB1FF0004, 0);
        func_8005DB40(0xB1FF0000, 0x49533634);
    }
}
