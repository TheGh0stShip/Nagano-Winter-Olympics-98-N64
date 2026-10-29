typedef struct Body {
    unsigned char pad0[0x58];
    float speed;
} Body;

extern unsigned char D_80136E75;
extern unsigned char D_80137140;
extern double D_8007FC78;
extern unsigned char func_80024478(int player);
extern float func_80020E70(Body *body, int player);
extern void func_8019C3D8(unsigned char a, unsigned char b, float speed);
extern void func_8019C5A0(unsigned char a, unsigned char b, float speed);

int func_80024CB0(float turn, unsigned char level, Body *body, int player) {
    int result;
    int pad;
    unsigned char busy;
    float speed;
    float a;

    busy = func_80024478(player);
    speed = func_80020E70(body, player);
    if (turn < 0.0f) {
        a = -turn;
    } else {
        a = turn;
    }
    if (a > D_8007FC78) {
        if (speed > 30.0f) {
            result = 16;
        } else {
            result = 32;
        }
        if (busy == 0) {
            func_8019C3D8(D_80137140, D_80136E75, speed);
        }
    } else {
        if (level >= 3) {
            result = 2;
        } else {
            result = 4;
        }
        if (busy == 0) {
            func_8019C5A0(D_80137140, level, body->speed);
        }
    }
    return result;
}
