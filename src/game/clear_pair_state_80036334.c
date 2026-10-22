typedef struct PairRecord {
    unsigned char pad0[0x96];
    unsigned short state;
} PairRecord;

extern PairRecord D_80137730[];
extern unsigned char D_8013772C;

void func_80036334(void) {
    short i;

    for (i = 0; i < 2; i++) {
        D_80137730[i].state = 0;
    }
    D_8013772C = 0;
}
