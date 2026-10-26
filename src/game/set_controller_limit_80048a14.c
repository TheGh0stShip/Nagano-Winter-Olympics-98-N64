extern unsigned char D_80179684[];

void func_80048A14(unsigned char index, unsigned char limit) {
    if (limit >= 21) {
        limit = 20;
    }
    if (index < 2) {
        D_80179684[index] = limit;
    } else {
        D_80179684[0] = limit;
        D_80179684[1] = limit;
    }
}
