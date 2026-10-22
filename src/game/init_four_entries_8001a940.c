extern void func_8001A980(unsigned char);

void func_8001A940(void) {
    unsigned char index;

    for (index = 0; index < 4; index++) {
        func_8001A980(index);
    }
}
