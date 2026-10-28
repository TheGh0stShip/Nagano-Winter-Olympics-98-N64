extern unsigned char D_8006E5E4;
extern void func_800485AC(int value);

void func_80011CE4(unsigned char *value) {
    if ((D_8006E5E4 = *value) != 0) {
        func_800485AC(5);
    } else {
        func_800485AC(6);
    }
}
