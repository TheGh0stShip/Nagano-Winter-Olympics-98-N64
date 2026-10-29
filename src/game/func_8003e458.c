typedef struct {
    unsigned char name[9];
    unsigned char unk9;
    char padA[2];
    float score;
    unsigned char unk10;
    char pad11;
    unsigned char rank;
    char pad13;
    short stat[7];
    short total;
    unsigned char sub[8];
} Entry;
typedef struct {
    unsigned char name[10][9];
    unsigned char unk5A[10];
    unsigned char sub[10][8];
    unsigned char stat[10][7];
} Src;
extern Entry D_80137DF8[10];
extern void func_80038B20(void *, void *, int);
void func_8003E458(Src *arg0) {
    unsigned char i;
    int j;
    int k;
    int sum;
    Entry *e;
    i = 0;
    for (j = 0; j < 10; j++) {
        e = &D_80137DF8[j];
        func_80038B20(e, arg0->name[j], 8);
        e->unk9 = arg0->unk5A[j];
        sum = 0;
        for (k = 0; k < 7; k++) {
            sum += arg0->stat[j][k];
            e->stat[k] = arg0->stat[j][k];
            e->sub[k] = arg0->sub[j][k];
        }
        e->total = sum;
        e->score = sum;
        e->sub[7] = arg0->sub[j][7];
        e->unk10 = arg0->sub[j][7] + 1;
        if (j > 0) {
            if (e->score == e[-1].score) {
                e->rank = e[-1].rank;
            } else {
                e->rank = i;
            }
        }
        i++;
    }
}
