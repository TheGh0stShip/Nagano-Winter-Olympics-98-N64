typedef struct {
    char data[0x138];
} Ent;
typedef struct {
    unsigned short s[7];
} Pad;
typedef struct {
    char pad0[0x7C8F4];
    Pad pads[(0x83EF8 - 0x7C8F4) / 14];
    Ent ents[13 * 4];
    char pad2[0x88A88 - 0x83EF8 - 13 * 4 * 0x138];
    unsigned short a88;
    char pad3[0x88A94 - 0x88A8A];
    float scroll;
    char pad4[0x88BB4 - 0x88A98];
    int bb4;
    char pad5[0x88BC0 - 0x88BB8];
    unsigned short bc0;
    char pad6[0x88BCC - 0x88BC2];
    float target;
    char pad7[0x88CEC - 0x88BD0];
    int cec;
    char pad8[0x977F0 - 0x88CF0];
    unsigned char count;
    unsigned char mode;
} Big;
extern Big *D_80126BF0;
typedef struct {
    char pad0[0xA88];
    unsigned short a88;
    char pad3[0xA94 - 0xA8A];
    float scroll;
    char pad4[0xBB4 - 0xA98];
    int bb4;
    char pad5[0xBC0 - 0xBB8];
    unsigned short bc0;
    char pad6[0xBCC - 0xBC2];
    float target;
    char pad7[0xCEC - 0xBD0];
    int cec;
} Sub;
#define S ((Sub *)((char *)D_80126BF0 + 0x88000))

extern unsigned char D_80137704;
extern volatile unsigned char D_80072A38;
extern unsigned char D_80072A34[];
extern unsigned char D_80072A30[];
extern unsigned char D_80072A2C[];
extern unsigned char D_80072A28[];
extern unsigned char D_80072A24[];
extern unsigned char D_80072A20[];
extern unsigned char D_80072A1C[];
extern unsigned char D_80072A18[];
extern unsigned char D_80072A14[];
extern unsigned char D_80072A10[];
extern unsigned char D_80072A0C[];
extern unsigned char D_80072A08[];
extern unsigned char D_80072A3C[];
extern int D_80072444;
extern int D_80072448;
extern float D_80080300;
extern float D_80080304;
extern void func_800348DC(void);
extern void func_8000ED68(unsigned char *);
extern void func_8000EC50(unsigned char *);
extern void func_8002FD8C(Ent *, int, int, int);
extern void func_8003492C(unsigned char);
extern short func_80033FE8(unsigned char *, unsigned char *);
extern short func_800343DC(short, unsigned char *);
extern void func_800348FC(int);
extern void func_80034958(float);

short func_80033984(void) {
    short ret;
    short flag;
    short pad;
    short pad2;
    short n;
    unsigned char buf1[0xC4];
    unsigned char buf0[0x114];
    short i;
    short j;
    short end;
    int v;


    ret = 0;
    func_800348DC();
    if (D_80137704 == 0) {
        n = D_80126BF0->count;
    } else if (D_80137704 == 1) {
        if (D_80126BF0->mode == 0x14) {
            func_8000ED68(buf1);
            n = buf1[1];
        } else {
            func_8000EC50(buf0);
            n = buf0[1];
        }
    }
    flag = 0;
    for (i = 0; i < n; i++) {
        if (D_80126BF0->pads[i].s[0] == 0) {
            for (j = i * 8, flag = 1; j < i * 8 + 8; j++) {
                func_8002FD8C(&D_80126BF0->ents[j], 0x3F, 0x3F, 0x3F);
            }
            for (j = 9; j < 13; j++) {
                if (j == 10) {
                    func_8002FD8C(&D_80126BF0->ents[j * 4 + i], 0x7F, 0x7F, 0x7F);
                } else {
                    func_8002FD8C(&D_80126BF0->ents[j * 4 + i], 0, 0, 0);
                }
            }
        } else {
            for (j = i * 8; j < i * 8 + 8; j++) {
                func_8002FD8C(&D_80126BF0->ents[j], 0x7F, 0x7F, 0x7F);
            }
            for (j = 9; j < 13; j++) {
                func_8002FD8C(&D_80126BF0->ents[j * 4 + i], 0x7F, 0x7F, 0x7F);
            }
        }
    }
    i = 0;
    if (flag) {
        if ((pad = D_80072A08[48]) < 0xC0) {
            D_80072A34[4] = pad + 4;
        }
        S->bc0 = 1;
        S->a88 = S->bc0;
        if (D_80126BF0->pads[0].s[0] == 0) {
            S->target = S->scroll + 320.0f + 224.0f - 170.0f;
            v = D_80072444;
            if ((v | 0) != S->bb4) {
                S->cec = v;
                S->bb4 = v;
                if (S->target < 320.0f) {
                    S->scroll = S->target;
                } else if (S->scroll < 0.0f) {
                    S->scroll = D_80080300;
                }
            }
            if (S->scroll < -224.0f) {
                S->scroll = S->target;
            }
        } else {
            S->target = S->scroll + 320.0f + 436.0f - 100.0f;
            v = D_80072448;
            if ((v | 0) != S->bb4) {
                S->cec = v;
                S->bb4 = v;
                if (S->target < 320.0f) {
                    S->scroll = S->target;
                } else if (S->scroll < 0.0f) {
                    S->scroll = D_80080304;
                }
            }
            if (S->scroll < -436.0f) {
                S->scroll = S->target;
            }
        }
    } else if ((pad = D_80072A30[8]) > 0) {
        D_80072A2C[12] = pad - 4;
    }
    func_8003492C(D_80072A28[16]);
    if (D_80072A24[20] > 0x60) {
        S->scroll -= 1.0f;
    } else {
        S->bc0 = 0;
        S->a88 = S->bc0;
    }
    if (D_80137704 == 0) {
        ret = func_80033FE8(D_80072A3C - 4, D_80072A3C);
    } else if (D_80137704 == 1) {
        ret = func_800343DC(flag, D_80072A3C);
    }
    if (ret) {
        for (i = 0; i < 4; i++) {
            D_80072A3C[i] = 0;
        }
        D_80072A20[24] = 0;
        i = 0;
    }
    for (; i < 4; i++) {
        func_800348FC((i + 0x20) & 0xFF);
    }
    func_80034958(-60.0f);
    return ret;
}

