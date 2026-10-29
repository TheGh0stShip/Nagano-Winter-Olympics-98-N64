#define F3DEX_GBI
#include "PR/mbi.h"
typedef struct {
    char pad0[8];
    float f8;
    char padC[0x128 - 0xC];
    int unk128;
    Gfx *unk12C;
} Obj;

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern unsigned char D_8006F640[][10];
extern unsigned short D_06000000[];
extern Gfx D_06004400[];
extern unsigned char D_06004478[];
extern unsigned char D_060044B8[];
extern int func_80005E18(int, void *);
extern void func_80017F0C(int, unsigned short, unsigned short);


void func_800196B8(Obj *arg0, unsigned short arg1, unsigned short arg2) {
    unsigned short *pa1 = &arg1;
    unsigned char *str;
    unsigned short k;
    unsigned char flag;
    unsigned short start;
    unsigned char prev;
    signed char i;
    int idx;
    int vtxA;
    int vtxB;
    unsigned char *p;
    unsigned char d;
    unsigned short n;
    int pad[2];

    flag = 0;
    n = 7;
    start = 0;
    idx = (unsigned short)arg0->f8;
    if (idx >= 0 && idx < 20) {
        if (arg1 != 0) {
            n = 6;
        }
        str = D_8006F640[idx];
        if (str != 0) {
            arg0->unk12C = D_80126BF4;
            gSPSegment(D_80126BF4++, 6, *(int *)(D_80126BF0 + 0x7C930));
            gSPDisplayList(D_80126BF4++, D_06004400);
            gDPPipeSync(D_80126BF4++);
            gDPLoadTLUT_pal256(D_80126BF4++, D_06000000);
            gDPPipeSync(D_80126BF4++);
            vtxA = func_80005E18(1, D_06004478);
            vtxB = func_80005E18(1, D_060044B8);
            p = str;
            for (i = 0; i < n; i++, p++) {
                d = *p - '0';
                if ((i == 0 || i == 2) && d == 0) {
                    continue;
                }
                if (i == 1 && d == 0) {
                    flag = 1;
                    continue;
                }
                start = i;
                break;
            }
            prev = d = 0xFF;
            p = str + (int)n - 1;
            k = 0;
            if (arg1 != 0) {
                k = 1;
            }
            if (k) {}
            for (i = n - 1; i >= start; i--, p--, k++) {
                if (p) {}
                d = *p - '0';
                if (d >= 10) {
                    d = 0;
                }
                if (d) {} if (d) {}
                gDPPipeSync(D_80126BF4++);
                if (k != 0) {
                    gSPMatrix(D_80126BF4++, vtxB, 0);
                }
                gSPVertex(D_80126BF4++, vtxA, 4, 0);
                if (d != prev) {
                    func_80017F0C(1, arg2, d);
                }
                prev = d;
                if (d) {}
                gSP2Triangles(D_80126BF4++, 2, 1, 0, 0, 3, 0, 1, 0);
                if ((k == 2 || k == 4) && (k != 4 || flag != 1)) {
                    gDPPipeSync(D_80126BF4++);
                    prev = 0xFF;
                    gSPMatrix(D_80126BF4++, vtxB, 0);
                    gSPVertex(D_80126BF4++, vtxA, 4, 0);
                    if (k == 2) {
                        func_80017F0C(1, arg2, 0xB);
                    }
                    if (k == 4) {
                        func_80017F0C(1, arg2, 0xA);
                    }
                    if (d) {}
                    gSP2Triangles(D_80126BF4++, 2, 1, 0, 0, 3, 0, 1, 0);
                }
            }
            if (prev) {}
            gDPPipeSync(D_80126BF4++);
            gSPMatrix(D_80126BF4++, vtxB, 0);
            gSPVertex(D_80126BF4++, vtxA, 4, 0);
            if (str[7] == '-') {
                func_80017F0C(1, arg2, 0xC);
            } else {
                func_80017F0C(1, arg2, 0xE);
            }
            gSP2Triangles(D_80126BF4++, 2, 1, 0, 0, 3, 0, 1, 0);
            gDPPipeSync(D_80126BF4++);
            gSPSegment(D_80126BF4++, 6, ((int *)(D_80126BF0 + 0x7C92C))[arg0->unk128]);
            gSPEndDisplayList(D_80126BF4++);
        }
    }
}
