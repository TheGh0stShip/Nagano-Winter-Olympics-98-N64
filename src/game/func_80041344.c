typedef struct Row {
    unsigned char v[7];
    unsigned char flag;
    unsigned char pad;
} Row;

typedef struct Buf {
    unsigned char count;
    unsigned char n;
    unsigned char seed[4];
    Row rows[16];
    unsigned char nib[16];
    unsigned char pair[15][2];
} Buf;

typedef struct Out {
    unsigned char count;
    unsigned char n;
    unsigned char seed[2];
    unsigned char rows[16][7];
    unsigned char nib[8];
    unsigned char pair[15][2];
} Out;

extern void func_8000ED68(Buf *buf);

void func_80041344(Out *out) {
    Buf buf;
    short i;
    short k;
    unsigned char c;
    unsigned char n;

    func_8000ED68(&buf);
    i = 0;
    if (out->count = buf.count) {
        out->n = buf.n;
        out->seed[0] = out->seed[1] = 0;
        if (out->n > 0) {
            do {
                out->seed[i / 2] |= (i % 2) ? (buf.seed[i] << 4) : (buf.seed[i] & 0xF);
                i++;
            } while (i < out->n);
            i = 0;
        }
        for (; i < 16; i++) {
            for (k = 0; k < 7; k++) {
                out->rows[i][k] = buf.rows[i].v[k] + ((buf.rows[i].flag & (1 << k)) << (7 - k));
            }
        }
        for (i = 0; i < 8; i++) {
            out->nib[i] = 0;
        }
        for (i = 0; i < 16; i++) {
            out->nib[i / 2] |= (buf.nib[i] & 0xF) << ((i % 2) * 4);
        }
        for (i = 0; i < 15; i++) {
            for (k = 0; k < 2; k++) {
                out->pair[i][k] = buf.pair[i][k];
            }
        }
    }
}
