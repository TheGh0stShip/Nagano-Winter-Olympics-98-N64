extern void func_8003C080(int, unsigned short *, unsigned short *);

void func_8003BFC8(int mode, unsigned short *first, unsigned short *second) {
    int i;
    unsigned short first_part;
    unsigned short second_part;

    if (mode >= 4) {
        *first = 0;
        *second = 0;
        for (i = 0; i < 4; i++) {
            func_8003C080(i, &first_part, &second_part);
            *first |= first_part;
            *second |= second_part;
        }
    } else {
        func_8003C080(mode, first, second);
    }
}
