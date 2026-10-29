typedef struct PakQuery {
    unsigned int size;
    unsigned int code;
    unsigned short tag;
    unsigned char zero[4];
    unsigned char name[16];
} PakQuery;

extern unsigned char D_800730AC;
extern unsigned char *D_800730A0[];
extern int func_80013B0C(int, PakQuery *, unsigned int, int *);
extern int func_80040CC4(unsigned char, int);

short func_80040900(void) {
    PakQuery q;
    int fileSize;
    short i;
    short out;

    q.size = 0x2000;
    q.code = 0x4E48354A;
    q.tag = 0x4134;
    for (i = 0; i < 4; i++) {
        q.zero[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        q.name[i] = D_800730A0[D_800730AC][i];
    }
    switch (func_80013B0C(0, &q, q.size, &fileSize)) {
    case 0:
        for (i = 0; i < 4; i++) {
            out = func_80040CC4(i, fileSize); if ((short)out != 0) {
                break;
            }
        }
        if ((short)out == 0) {
            out = *(short *)((char *)&fileSize + 2);
        }
        break;
    case 7:
        out = -1;
        break;
    case 8:
        out = -2;
        break;
    case 9:
        out = -3;
        break;
    default:
        out = -3;
    }
    return out;
}
