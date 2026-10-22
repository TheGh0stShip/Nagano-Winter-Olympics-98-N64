int func_8005A7D0(int *record, int mode, int value) {
    switch (mode) {
        case 1:
            record[0] = value;
            break;
        case 6:
            record[5] = value;
            break;
    }
    return 0;
}
