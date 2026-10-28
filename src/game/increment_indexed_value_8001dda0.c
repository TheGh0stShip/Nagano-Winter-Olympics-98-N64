typedef struct Racer {
    float angle;
    float speed;
    unsigned char pad8[0x70];
} Racer;

extern unsigned char *D_80126BF0;
extern int D_80136704;
extern int D_8006F7C4;
extern void func_8000AAC0(void);

void func_8001DDA0(void) {
    if (D_80136704) {
        func_8000AAC0();
        ((Racer *)(D_80126BF0 + 0x7FB50))[D_8006F7C4].speed += 0.2f;
    }
}
