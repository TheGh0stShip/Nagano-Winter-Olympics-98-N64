extern unsigned char *D_80126BF0;

int func_80036FC4(void) {
    int size;

    if (D_80126BF0[0x977F1] == 21) {
        return 0x800;
    }
    switch (D_80126BF0[0x977EC]) {
        case 4:
            size = 0xA00;
            break;
        case 2:
        case 3:
        case 5:
            size = 0x900;
            break;
        case 0:
        case 1:
        case 6:
        case 7:
        case 8:
        case 9:
            size = 0x600;
            break;
        case 10:
            size = 0x400;
            break;
        default:
            size = 0x800;
            break;
    }
    return size;
}
