typedef struct Tbl {
    unsigned char name[16][9];
    unsigned char b90[16];
    unsigned char a0[16][7];
    unsigned char a110[16][7];
    unsigned char b180[16];
    float f190[16];
    float f1D0[16];
    float f210[16];
} Tbl;

typedef struct Tmp {
    unsigned char name[9];
    unsigned char b90;
    unsigned char b180;
    unsigned char a0[7];
    unsigned char a110[7];
    float f190;
    float f1D0;
    float f210;
} Tmp;

extern Tbl D_80137150;

void func_8002B228(unsigned char a, unsigned char b) {
    unsigned short i;
    Tmp t;

    for (i = 0; i < 9; i++) { t.name[i] = D_80137150.name[b][i]; }
    t.b90 = D_80137150.b90[b];
    t.f190 = D_80137150.f190[b];
    t.b180 = D_80137150.b180[b];
    t.f1D0 = D_80137150.f1D0[b];
    t.f210 = D_80137150.f210[b];
    for (i = 0; i < 7; i++) { t.a0[i] = D_80137150.a0[b][i]; t.a110[i] = D_80137150.a110[b][i]; }
    for (i = 0; i < 9; i++) { D_80137150.name[b][i] = D_80137150.name[a][i]; }
    D_80137150.b90[b] = D_80137150.b90[a];
    D_80137150.f190[b] = D_80137150.f190[a];
    D_80137150.b180[b] = D_80137150.b180[a];
    D_80137150.f1D0[b] = D_80137150.f1D0[a];
    D_80137150.f210[b] = D_80137150.f210[a];
    for (i = 0; i < 7; i++) { D_80137150.a0[b][i] = D_80137150.a0[a][i]; D_80137150.a110[b][i] = D_80137150.a110[a][i]; }
    for (i = 0; i < 9; i++) { D_80137150.name[a][i] = t.name[i]; }
    D_80137150.b90[a] = t.b90;
    D_80137150.f190[a] = t.f190;
    D_80137150.b180[a] = t.b180;
    D_80137150.f1D0[a] = t.f1D0;
    D_80137150.f210[a] = t.f210;
    for (i = 0; i < 7; i++) { D_80137150.a0[a][i] = t.a0[i]; D_80137150.a110[a][i] = t.a110[i]; }
}
