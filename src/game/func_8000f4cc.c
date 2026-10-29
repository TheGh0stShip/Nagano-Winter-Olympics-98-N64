typedef struct SaveBlockB {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2[16][9];
    unsigned char unk92[16];
    unsigned char unkA2[16][7];
} SaveBlockB;

extern SaveBlockB D_801335E0;

void func_8000F4CC(void) {
    short i;
    short j;

    D_801335E0.unk0 = 0;
    D_801335E0.unk1 = 0;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 9; j++) {
            D_801335E0.unk2[i][j] = 0;
        }
    }
    for (i = 0; i < 16; i++) {
        D_801335E0.unk92[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 9; j++) {
            D_801335E0.unkA2[i][j] = 0;
        }
    }
}
