extern unsigned char D_801366F0[];
extern void func_80048580(int);

void func_8001E1C8(int index) {
    if (D_801366F0[index] != 1) {
        switch (index) {
        case 0:
        case 2:
            func_80048580(9);
            break;
        case 1:
            func_80048580(38);
            break;
        }
        D_801366F0[index] = 1;
    }
}
