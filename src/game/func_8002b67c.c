typedef struct Runtime {
    unsigned char pad0[0x977EC];
    unsigned char mode;
    unsigned char pad977ED[2];
    unsigned char round;
    unsigned char rounds;
    unsigned char event;
    unsigned char count;
} Runtime;

extern Runtime *D_80126BF0;
extern unsigned char D_80071A68[];

int func_8002B67C(void) {
    int result = 0;

    if (D_80126BF0->round + 1 < D_80126BF0->rounds) {
        D_80126BF0->round++;
    } else {
        D_80126BF0->round = 0;
        D_80126BF0->count++;
        if (D_80126BF0->count == D_80071A68[D_80126BF0->mode]) {
            result = 1;
        }
        if (D_80126BF0->event == 21) {
            result = 1;
        }
    }
    return result;
}
