extern unsigned char func_80005F78(int index, int id);
extern unsigned char func_80005FA4(int index, int id);
extern void func_8000C190(int id);

void func_80005FD0(unsigned char mode, unsigned char *state, int index, int id) {
    unsigned char result;

    *state = 1;
    switch (mode) {
    case 0:
        result = func_80005F78(index, id);
        break;
    case 1:
        result = func_80005FA4(index, id);
        break;
    default:
        result = func_80005F78(index, id);
        break;
    }
    if (result) {
        if (result == 2) {
            func_8000C190(id);
        }
        if (result == 3) {
            *state = 0;
        }
        *state = 3;
    }
}
