typedef struct Entry {
    char name[9];
    unsigned char unk9;
    char padA[2];
    float unkC;
    char pad10;
    unsigned char unk11;
    unsigned char unk12;
    char pad13;
    short unk14[7];
    short unk22;
    unsigned char unk24[7];
    unsigned char unk2B;
} Entry;

typedef struct Src {
    char name[16][9];
    unsigned char unk90[16];
    unsigned char unkA0[16][7];
    unsigned char unk110[16][7];
    unsigned char unk180[16];
    float unk190[16];
} Src;

typedef struct Game {
    char pad[0x977F1];
    unsigned char unk977F1;
} Game;

extern Entry D_80137DF8[16];
extern Game *D_80126BF0;
extern void func_80038B20(char *dst, char *src, int n);

void func_8003E078(Src *src) {
    int k;
    unsigned char i;
    int j;
    int v;
    float sum;
    Entry *e;

    i = 0;
    for (k = 0; k < 16; k++) {
        e = &D_80137DF8[k];
        func_80038B20(e->name, src->name[k], 8);
        e->unk9 = src->unk90[k];
        e->unkC = src->unk190[k];
        e->unk11 = src->unk180[k];
        if (D_80126BF0->unk977F1 == 0x15) {
            e->unkC = (int)e->unkC;
        }
        sum = 0.0f;
        for (j = 0; j < 7; j++) {
            v = src->unkA0[k][j];
            e->unk14[j] = v;
            e->unk24[j] = src->unk110[k][j];
            sum += v;
        }
        e->unk22 = sum;
        if (k > 0) {
            if (e->unkC == e[-1].unkC) {
                e->unk12 = e[-1].unk12;
            } else {
                e->unk12 = i;
            }
        }
        e->unk2B = e->unk12;
        i++;
    }
}
