typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    u8 pad0[9];
    u8 f9;
    u8 padA[2];
    float fC;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 pad13;
    u16 h[8];
    u8 b[8];
    u8 pad2C[0];
} Rec;
extern Rec D_80137DF8[16];
extern u8 D_800804C4[];
extern void func_80038B20(u8 *, u8 *, int);

void func_8003DFA8(void) {
    Rec *p;
    int i;
    int j;

    for (i = 0, p = D_80137DF8; i < 16; i++, p++) {
        func_80038B20((u8 *)p, D_800804C4, 8);
        p->f9 = 0;
        p->fC = 0.0f;
        p->f10 = 0;
        p->f11 = 0;
        p->f12 = i;
        for (j = 0; j < 8; j++) {
            p->h[j] = 0;
            p->b[j] = 0;
        }
    }
}
