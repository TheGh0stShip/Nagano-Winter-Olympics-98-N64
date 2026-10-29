typedef struct Roster {
    unsigned char rec[24][9];
    unsigned char flag[24];
    unsigned char pad[0x18];
    float score[24];
} Roster;

typedef struct Saved {
    unsigned char rec[9];
    unsigned char flag;
    unsigned char pad[0x12];
    float score;
    unsigned char tail[8];
} Saved;

void func_80028770(unsigned char a, unsigned char b, Roster *r) {
    unsigned short i;
    Saved tmp;

    for (i = 0; i < 9; i++) {
        tmp.rec[i] = r->rec[b][i];
    }
    tmp.flag = r->flag[b];
    tmp.score = r->score[b];
    for (i = 0; i < 9; i++) {
        r->rec[b][i] = r->rec[a][i];
    }
    r->flag[b] = r->flag[a];
    r->score[b] = r->score[a];
    for (i = 0; i < 9; i++) {
        r->rec[a][i] = tmp.rec[i];
    }
    r->flag[a] = tmp.flag;
    r->score[a] = tmp.score;
}
