typedef struct {
    char pad0[0x180];
    unsigned char place[16];
    float t[16];
    float a[16];
    float b[16];
} Race;

extern Race D_80137150;
extern unsigned char D_801374C0[][4];
extern signed char D_80071A50[];
extern unsigned char* D_80126BF0;
extern unsigned char D_801374B2;

void func_80029870(void) {
    unsigned char i;
    int p;
    unsigned char act;
    unsigned char act2;

    for (i = 0; i < 16; i++) {
        if (D_801374B2 == 7 && D_80137150.place[i] != 0) {
            if ((int)D_80137150.a[i] == 0 && D_80126BF0[0x977F2] == 0) {
                if (D_80126BF0[0x977EF] + 1 == D_80137150.place[i]) {
                    D_80137150.t[i] = 1000000.0f;
                } else {
                    D_80137150.t[i] += 1000005.0f;
                }
            } else if ((int)D_80137150.b[i] == 0 && D_80126BF0[0x977F2] == 1) {
                if (D_80126BF0[0x977EF] + 1 == D_80137150.place[i]) {
                    D_80137150.t[i] = 1000000.0f;
                } else {
                    D_80137150.t[i] += 1000005.0f;
                }
            } else {
                goto other;
            }
        } else {
        other:
            act = (act & 0) | 0;
            if (act || D_801374B2 == 4 || D_801374B2 == 2 || D_801374B2 == 3) {
                p = D_80126BF0[0x977EF];
                if (p + 1 == D_80137150.place[i] &&
                    D_801374C0[D_80126BF0[0x977F2]][p] != 0) {
                    D_80137150.t[i] = -1.0f;
                }
            }
            if (D_80071A50[D_80126BF0[0x977EC]] > 0 &&
                ((act = (act & 0) | 0) || !(act2 = (act2 & 0) | 0))) {
                if ((int)D_80137150.t[i] == -1) {
                    D_80137150.t[i] = 1000000.0f;
                } else if ((int)D_80137150.t[i] == 0 && D_80071A50[D_801374B2] == 1) {
                    D_80137150.t[i] = 1000001.0f;
                }
            }
        }
    }
}
