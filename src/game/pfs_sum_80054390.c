unsigned short func_80054390(unsigned char *data, int length) {
    int i;
    unsigned int sum = 0;
    unsigned char *current = data;

    for (i = 0; i < length; i++) {
        sum += *current++;
        sum &= 0xFFFF;
    }
    return sum;
}
