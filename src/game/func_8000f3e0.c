typedef struct SaveBlockA {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2[4];
    unsigned char unk6[16][9];
    unsigned char unk96[16];
    unsigned char unkA6[15][2];
} SaveBlockA;

extern SaveBlockA D_80133F48;

void func_8000F3E0(void) {
    short i;
    short j;

    D_80133F48.unk0 = 0;
    D_80133F48.unk1 = 0;
    for (i = 0; i < 4; i++) {
        D_80133F48.unk2[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 9; j++) {
            D_80133F48.unk6[i][j] = 0;
        }
    }
    for (i = 0; i < 16; i++) {
        D_80133F48.unk96[i] = 0;
    }
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 2; j++) {
            D_80133F48.unkA6[i][j] = 0;
        }
    }
}
