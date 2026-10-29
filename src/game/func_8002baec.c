typedef struct Game {
    unsigned char pad[0x977EC];
    unsigned char course;
    unsigned char pad977ED[3];
    unsigned char count;
    unsigned char mode;
} Game;

typedef struct Times {
    unsigned char pad[0x190];
    float best[4];
} Times;

extern Game *D_80126BF0;
extern Times D_80137150;
extern signed char D_80071A50[];
extern int func_8002B5D0(unsigned char);
extern float func_8000FAA8(unsigned char);
extern void func_80048580(int);

void func_8002BAEC(void) {
    unsigned char best = 0xFF;
    unsigned char i;
    int r;
    float s;
    float f;
    float a;
    float b;

    if (D_80126BF0->mode != 0x15) {
        for (i = 0; i < D_80126BF0->count; i++) {
            r = func_8002B5D0(i);
            if (r < best) {
                best = r;
            }
        }
        if (D_80137150.best[best] <= 0.0f) {
            func_80048580(0x3F3);
            return;
        }
        a = func_8000FAA8(D_80126BF0->course) * D_80071A50[D_80126BF0->course];
        b = D_80137150.best[0] * D_80071A50[D_80126BF0->course];
        if (best == 0 && b <= a && func_8000FAA8(D_80126BF0->course) >= 1.0f) {
            func_80048580(0x3F0);
            return;
        }
        if (best < 3) {
            func_80048580(0x3F1);
            return;
        }
        func_80048580(0x3F2);
    }
}
