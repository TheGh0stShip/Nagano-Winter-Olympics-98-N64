typedef struct Roster {
    unsigned char rec[24][9];
    unsigned char flag[24];
    unsigned char pad[0x18];
    float score[24];
} Roster;

typedef struct Name {
    unsigned char text[9];
    unsigned char flag;
    unsigned char pad[4];
} Name;

extern unsigned char D_801374B2;
extern Name D_8006D470[][24];
extern float func_800289B4(unsigned short index);
extern int func_800296C0(float a, float b);

void func_80028864(unsigned short index, Roster *r) {
    float score;
    unsigned short i;
    unsigned short j;
    int found;

    i = 0;
    found = 0;
    while (1) {
        score = func_800289B4(index);
        for (; i < 24; i++) {
            if (func_800296C0(score, r->score[i])) { found = 1; break; }
        }
        if (!found) break;
        i = 0;
        found = 0;
    }
    r->score[index] = score;
    for (j = 0; j < 9; j++) {
        r->rec[index][j] = D_8006D470[D_801374B2][index].text[j];
    }
    r->flag[index] = D_8006D470[D_801374B2][index].flag;
}
