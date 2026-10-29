typedef struct Buf {
    unsigned char count;
    unsigned char pad1;
    unsigned char seed[0xA4];
    unsigned char pair[15][2];
} Buf;

typedef struct Out {
    unsigned char wins;
    unsigned char lost;
} Out;

extern void func_8000ED68(Buf *buf);

void func_80035004(short idx, Out *out) {
    Buf buf;
    short levels[4] = { 0, 8, 12, 14 };
    short i;
    short j;
    short rem;
    short q;

    if (1) {
        func_8000ED68(&buf);
    }
    j = 0;
    while (buf.count >= levels[j + 1]) {
        j++;
    }
    i = j;
    rem = buf.count - levels[i];
    out->lost = 0;
    out->wins = 0;
    for (j = 0; j <= i; j++) {
        if (i) {}
        q = buf.seed[idx] / (1 << j);
        if (j == i && q / 2 >= rem) {
            return;
        }
        if (buf.pair[levels[j] + q / 2][q % 2] < buf.pair[levels[j] + q / 2][(q ^ 1) % 2]) {
            out->lost = 1;
            return;
        }
        out->wins++;
    }
}

