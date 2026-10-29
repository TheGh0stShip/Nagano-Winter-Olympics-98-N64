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
    float pad1D0[16];
    float time[16];
} Tbl;

extern Game *D_80126BF0;
extern unsigned char D_80071A68[];
extern Tbl D_80137150;
extern unsigned char D_801374B2;
extern void func_8000EE24(int, unsigned char *, int, int, float);

void func_8002A37C(void) {
    unsigned short i;

    if (D_80126BF0->c + 1 == D_80071A68[D_801374B2]) {
        if (D_80126BF0->a + 1 == D_80126BF0->b) {
            for (i = 0; i < 16; i++) {
                if (D_80126BF0->mode == 7 && D_80071A68[D_801374B2] == 2 && D_80137150.time[i] <= 0.0f) {
                    continue;
                }
                if (D_80137150.active[i] != 0) {
                    func_8000EE24(D_801374B2, D_80137150.names[i], D_80137150.kind[i], (unsigned char)i, D_80137150.val[i]);
                }
            }
        }
    }
}
