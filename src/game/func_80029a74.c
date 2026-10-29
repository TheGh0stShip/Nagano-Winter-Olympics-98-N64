typedef struct Game {
    unsigned char pad0[0x977EC];
    unsigned char mode;
    unsigned char pad977ED[2];
    unsigned char a;
    unsigned char b;
    unsigned char pad977F1;
    unsigned char c;
} Game;

typedef struct Tbl {
    unsigned char names[16][9];
    unsigned char kind[16];
    unsigned char pad[0x180 - 0xA0];
    unsigned char active[16];
    float val[16];
    float flag[16];
    float time[16];
} Tbl;

extern Game* D_80126BF0;
extern signed char D_80071A50[];
extern Tbl D_80137150;
extern unsigned char D_801374B2;

void func_80029A74(void) {
    unsigned char i;
    unsigned char act;
    unsigned char act2;

    for (i = 0; i < 16; i++) {
        if (D_801374B2 == 7 && D_80137150.active[i] != 0) {
            if ((int)D_80137150.flag[i] == 0 && D_80126BF0->c == 0) {
                if (D_80126BF0->a + 1 == D_80137150.active[i]) {
                    D_80137150.val[i] -= 1000000.0f;
                    D_80137150.val[i] -= 1.0f;
                } else {
                    D_80137150.val[i] -= 1000005.0f;
                }
                continue;
            } else if ((int)D_80137150.time[i] == 0 && D_80126BF0->c == 1) {
                if (D_80126BF0->a + 1 == D_80137150.active[i]) {
                    D_80137150.val[i] -= 1000000.0f;
                    D_80137150.val[i] -= 1.0f;
                } else {
                    D_80137150.val[i] -= 1000005.0f;
                }
                continue;
            }
        }
        if (D_80071A50[D_80126BF0->mode] > 0 &&
            ((act = (act & 0) | 0) || !(act2 = (act2 & 0) | 0))) {
            if ((int)D_80137150.val[i] == 1000000) {
                D_80137150.val[i] = -1.0f;
            } else if ((int)D_80137150.val[i] == 1000001) {
                D_80137150.val[i] = 0.0f;
            }
        }
    }
}
