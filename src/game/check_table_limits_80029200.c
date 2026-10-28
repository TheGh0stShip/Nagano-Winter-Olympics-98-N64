typedef struct Ranking {
    unsigned char pad[0x190];
    float limits[16];
} Ranking;

extern Ranking D_80137150;
extern int func_800296C0(float limit, float value);

int func_80029200(float value) {
    unsigned short i;

    for (i = 0; i < 16; i++) {
        if (func_800296C0(D_80137150.limits[i], value)) {
            return 1;
        }
    }
    return 0;
}
