typedef unsigned short u16;

typedef struct RuntimeTextState {
    unsigned char names[16][9];
    unsigned char flags90[16];
    unsigned char valuesA0[16][7];
    unsigned char values110[16][7];
    unsigned char flags180[16];
    float values190[16];
    float values1D0[16];
    float values210[16];
} RuntimeTextState;

extern RuntimeTextState D_80137150;
extern unsigned char D_801374C0[2][4];

void func_80028C94(void) {
    u16 i;
    u16 j;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 9; j++) {
            D_80137150.names[i][j] = 0x20;
        }
        D_80137150.flags90[i] = 0;
        D_80137150.values190[i] = 0.0f;
        D_80137150.values1D0[i] = 0.0f;
        D_80137150.values210[i] = 0.0f;
        D_80137150.flags180[i] = 0;
        for (j = 0; j < 7; j++) {
            D_80137150.values110[i][j] = 0;
            D_80137150.valuesA0[i][j] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            D_801374C0[i][j] = 0;
        }
    }
}
