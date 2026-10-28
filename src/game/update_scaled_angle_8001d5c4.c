typedef struct Racer {
    float angle;
    unsigned char pad4[0x74];
} Racer;

extern unsigned char *D_80126BF0;
extern float D_801366EC;
extern int D_8006F7C4;

int func_8001D5C4(void) {
    float angle = D_801366EC / 640.0f * 90.0f;

    ((Racer *)(D_80126BF0 + 0x7FB50))[D_8006F7C4].angle = angle;
    if (angle >= 90.0f) {
        return 1;
    }
    return 0;
}
