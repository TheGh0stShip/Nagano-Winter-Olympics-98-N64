typedef struct SourceBlock {
    unsigned char a[10][9];
    unsigned char b[10];
    unsigned char c[10][8];
    unsigned char d[10][7];
    unsigned short e[3];
} SourceBlock;

typedef struct DestBlock {
    unsigned char a[10][7];
    unsigned char b[5];
    unsigned char c[10][4];
    unsigned char d[10][7];
    unsigned char pad;
    unsigned short e[3];
} DestBlock;

extern void func_8000ED18(void *destination);

void func_8004182C(DestBlock *dest) {
    SourceBlock src;
    int pad[2];
    short i;
    short j;
    int nibble;

    func_8000ED18(&src);
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 7; j++) {
            dest->a[i][j] = src.a[i][j] + ((src.a[i][7] & (1 << j)) << (7 - j));
        }
    }
    for (i = 0; i < 5; i++) {
        dest->b[i] = 0;
    }
    for (i = 0; i < 10; i++) {
        if (i % 2) {
            nibble = src.b[i] << 4;
        } else {
            nibble = src.b[i] & 0xF;
        }
        dest->b[i / 2] |= nibble;
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            dest->c[i][j] = 0;
        }
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 8; j++) {
            if (j % 2) {
                nibble = src.c[i][j] << 4;
            } else {
                nibble = src.c[i][j] & 0xF;
            }
            dest->c[i][j / 2] |= nibble;
        }
    }
    for (i = 0; i < 3; i++) {
        dest->e[i] = src.e[i];
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 7; j++) {
            dest->d[i][j] = src.d[i][j];
        }
    }
}
