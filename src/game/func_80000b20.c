#include "PR/mbi.h"

typedef struct GfxCtx {
    Gfx dl[3][0x5308];
    short idx;
    short mode;
    short pad;
    unsigned short siz;
} GfxCtx;

extern unsigned short D_800634E8;
extern char D_8008C650[];
extern GfxCtx *D_80126BF0;
extern Gfx *D_80126BF4;
extern unsigned short D_8036A000[];
extern unsigned short D_8038F800[];
extern unsigned short D_803B5000[];

extern void func_80000EF4(void);
extern void func_80000FA0(void);
extern void func_80000FCC(void);
extern void func_80003C38(void *, void *, int);
extern short func_80003EB0(void *);
extern unsigned int func_80004528(void *);
extern void func_800045B0(void *);
extern void func_8005F960(float);

void func_80000B20(void) {
    unsigned short x;
    unsigned short h;

    if ((func_80004528(D_8008C650) == 0 && !D_800634E8) ||
        (func_80004528(D_8008C650) < 2 && D_800634E8 && D_800634E8 <= 16)) {
        if (D_800634E8 == 0) {
            if (D_80126BF0->mode == 0) {
                func_80003C38(D_8036A000, D_8038F800, 0x25800);
            } else if (D_80126BF0->mode == 1) {
                func_80003C38(D_8038F800, D_803B5000, 0x25800);
            } else if (D_80126BF0->mode == 2) {
                func_80003C38(D_803B5000, D_8036A000, 0x25800);
            }
        }
        D_800634E8++;
        D_80126BF4 = D_80126BF0->dl[D_80126BF0->idx];
        func_80000EF4();
        func_80000FA0();
        gDPSetScissor(D_80126BF4++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        gDPPipeSync(D_80126BF4++);
        gDPSetCycleType(D_80126BF4++, G_CYC_FILL);
        gDPSetColorImage(D_80126BF4++, G_IM_FMT_RGBA, D_80126BF0->siz, 320,
                         (unsigned int)(D_8036A000 + D_80126BF0->idx * (320 * 240)) - 0x80000000);
        gDPSetFillColor(D_80126BF4++, 0x00010001);
        h = D_800634E8 * 16;
        for (x = 0; x <= 320; x += 8) {
            if (h > 240) {
                h = 240;
            }
            gDPFillRectangle(D_80126BF4++, x, 0, x + 4, h);
            gDPFillRectangle(D_80126BF4++, x + 5, 240 - h, x + 8, 240);
        }
        gDPPipeSync(D_80126BF4++);
        func_80000FCC();
        D_80126BF0->idx = func_80003EB0(D_8008C650);
        D_80126BF0->idx++;
        if (D_80126BF0->idx >= 3) {
            D_80126BF0->idx = 0;
        }
        if (D_800634E8 == 24) {
            func_8005F960(1.0f);
            func_800045B0(D_8008C650);
        }
    }
}
