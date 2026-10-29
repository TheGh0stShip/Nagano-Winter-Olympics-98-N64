extern char *D_8006F578[];

void func_8001C7DC(unsigned char index, unsigned int value, unsigned char count, unsigned char arg3) {
    char *s;
    unsigned char zero;
    unsigned int div;
    unsigned char i;
    unsigned char d;

    zero = 0;
    div = 1;
    s = D_8006F578[index];
    if (count == 0) {
        return;
    }
    for (i = 0; i < count; i++) {
        if ((int)(value / div) <= 0) {
            zero = 1;
        }
        d = value / div % 10;
        if ((unsigned char)(value / div % 10) == 0 && zero == 1) {
            return;
        }
        s[7 - i] = d + '0';
        div *= 10;
    }
}
