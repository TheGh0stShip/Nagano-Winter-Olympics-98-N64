extern unsigned char D_8006F640[][10];

void func_8001CD08(void) {
    unsigned short i;
    unsigned short j;
    unsigned char *p;
    unsigned char digits[10] = "0000000000";

    for (i = 0; i < 20; i++) {
        p = D_8006F640[i];
        for (j = 0; j < 10; j++) {
            *p++ = digits[j];
        }
    }
}
