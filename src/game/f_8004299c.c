typedef struct RecA {
    unsigned char name[10][9];
    unsigned char nibA[10];
    unsigned char nibB[10];
    unsigned char pad[6];
    float val[10];
} RecA;

typedef struct RecB {
    unsigned char raw[10][7];
    unsigned char nibA[5];
    unsigned char nibB[5];
    unsigned char pad[8];
    float val[10];
} RecB;

int func_8004299C(RecA *a, RecB *b) {
    short i;
    short j;
    unsigned char c;
    int diff;

    diff = 0;
    for (i = 0; i < 10; i++) {
        c = 0;
        for (j = 0; j < 7; j++) {
            if (a->name[i][j] != (b->raw[i][j] & 0x7F)) {
                diff = 1;
                break;
            }
            c += (b->raw[i][j] & 0x80) >> (7 - j);
        }
        if (a->name[i][j] != c) {
            diff = 1;
        }
        if (diff) {
            break;
        }
        if (a->nibA[i] != ((b->nibA[i / 2] >> (i % 2 * 4)) & 0xF)) {
            diff = 1;
            break;
        }
        if (a->val[i] != b->val[i]) {
            diff = 1;
            break;
        }
        if (a->nibB[i] != ((b->nibB[i / 2] >> (i % 2 * 4)) & 0xF)) {
            diff = 1;
        }
    }
    return diff;
}
