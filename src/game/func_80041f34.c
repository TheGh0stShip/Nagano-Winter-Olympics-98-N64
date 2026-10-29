typedef struct Team {
    unsigned char name[10][7];
    unsigned char lo[5];
    unsigned char hi[5];
    unsigned short c[3];
    unsigned short pad56;
    float f[10];
} Team;

typedef struct Rec {
    unsigned char name[10][9];
    unsigned char lo[10];
    unsigned char hi[10];
    unsigned short c[3];
    float f[10];
} Rec;

typedef struct Data {
    Team team[12];
    unsigned char pad600[0x40];
    unsigned short c[3];
} Data;

extern void func_8000F2B4(unsigned char id, Rec *rec);

void func_80041F34(Data *data) {
    Rec rec;
    int sh;
    short t;
    short i;
    short j;
    unsigned char bits;

    t = 0;
    for (; t < 12; t++) {
        if (t == 11) {
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 9; j++) { rec.name[i][j] = 0; }
                rec.lo[i] = 0;
                rec.f[i] = 0.0f;
            }
            for (i = 0; i < 3; i++) { rec.c[i] = data->c[i]; }
            func_8000F2B4(t, &rec);
        } else {
            i = 0;
            do {
                if (t) {}
                bits = 0;
                for (j = 0; j < 7; j++) {
                    if (t) {}
                    rec.name[i][j] = data->team[t].name[i][j] & 0x7F;
                    bits |= (data->team[t].name[i][j] & 0x80) >> (7 - j);
                }
                rec.name[i][7] = bits;
                rec.name[i][8] = 0;
                sh = (i % 2) * 4;
                rec.lo[i] = (data->team[t].lo[i / 2] >> sh) & 0xF;
                rec.f[i] = data->team[t].f[i];
                rec.hi[i] = (data->team[t].hi[i / 2] >> sh) & 0xF;
                i++;
            } while (i < 10);
            for (i = 0; i < 3; i++) { rec.c[i] = data->team[t].c[i]; }
            func_8000F2B4(t, &rec);
        }
    }
}
