#include "PR/ultratypes.h"
#include "PR/mbi.h"

typedef struct {
    u8 pad0[4];
    u16 state;
    u8 pad6[2];
    f32 speed;
    u8 padC[0x24];
    u16 mode;
    u8 pad32[3];
    u8 alpha;
    u8 pad36[0x12C - 0x36];
    Gfx *dl;
} Fader;

extern Gfx *D_80126BF4;
extern u8 D_8006C3D0;
extern s16 D_80072168;
extern u8 D_80072008[];
extern u8 D_80072030[];
extern u8 D_800720A8[];
extern u8 D_800720C8[];
extern u8 D_800720E8[];
extern f32 D_801376B0;
extern s16 D_801376B4;

#define LOAD4(tex) \
    gDPPipeSync(D_80126BF4++); \
    gDPLoadTextureBlock(D_80126BF4++, tex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 4, 0, \
        G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 2, 2, G_TX_NOLOD, G_TX_NOLOD); \
    gSPDisplayList(D_80126BF4++, D_80072008)

void func_80030F88(Fader *f) {
    s16 frame;
    f32 a;

    f->dl = D_80126BF4;
    gDPPipeSync(D_80126BF4++);
    gSPDisplayList(D_80126BF4++, D_80072030);
    if (D_8006C3D0 != 0) {
        frame = D_80072168 + 1;
        if (frame >= 8) {
            frame = 0;
        }
        gDPPipeSync(D_80126BF4++);
        gDPSetPrimColor(D_80126BF4++, 0, 0, 0, 0, 0, 0);
        gDPPipeSync(D_80126BF4++);
        gDPLoadTextureBlock(D_80126BF4++, D_800720E8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0,
            G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 3, 3, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetTileSize(D_80126BF4++, G_TX_RENDERTILE, frame * 2, frame * 2, 0x1C, 0x1C);
        gSPDisplayList(D_80126BF4++, D_80072008);
        gDPPipeSync(D_80126BF4++);
        D_80072168 = frame;
    } else {
        switch (f->state) {
        case 0:
        case 9:
            f->mode = 0;
            break;
        case 2:
            gDPPipeSync(D_80126BF4++);
            gDPSetPrimColor(D_80126BF4++, 0, 0, 255, 255, 255, f->alpha);
            LOAD4(D_800720A8);
            a = f->alpha - f->speed;
            if (a < 0.0f) {
                a = 0.0f;
            }
            if (a > 255.0f) {
                a = 255.0f;
            }
            f->alpha = a;
            D_801376B0 -= f->speed;
            if (D_801376B0 < 0.0f) {
                f->mode = 0;
                f->state = 9;
                D_801376B0 = 255.0f;
            }
            break;
        case 1:
            gDPPipeSync(D_80126BF4++);
            gDPSetPrimColor(D_80126BF4++, 0, 0, 255, 255, 255, f->alpha);
            LOAD4(D_800720A8);
            a = f->speed + f->alpha;
            if (a < 0.0f) {
                a = 0.0f;
            }
            if (a > 255.0f) {
                a = 255.0f;
            }
            f->alpha = a;
            D_801376B0 -= f->speed;
            if (D_801376B0 < 0.0f) {
                f->mode = 0;
                f->state = 6;
                D_801376B0 = 255.0f;
            }
            break;
        case 4:
            gDPPipeSync(D_80126BF4++);
            gDPSetPrimColor(D_80126BF4++, 0, 0, 0, 0, 0, f->alpha);
            LOAD4(D_800720C8);
            a = f->alpha - f->speed;
            if (a < 0.0f) {
                a = 0.0f;
            }
            if (a > 255.0f) {
                a = 255.0f;
            }
            f->alpha = a;
            D_801376B0 -= f->speed;
            if (D_801376B0 < 0.0f) {
                f->mode = 0;
                f->state = 9;
                D_801376B0 = 255.0f;
            }
            break;
        case 3:
            gDPPipeSync(D_80126BF4++);
            gDPSetPrimColor(D_80126BF4++, 0, 0, 0, 0, 0, f->alpha);
            LOAD4(D_800720C8);
            a = f->speed + f->alpha;
            if (a < 0.0f) {
                a = 0.0f;
            }
            if (a > 255.0f) {
                a = 255.0f;
            }
            f->alpha = a;
            D_801376B0 -= f->speed;
            if (D_801376B0 < 0.0f) {
                f->mode = 0;
                f->state = 5;
                D_801376B0 = 255.0f;
            }
            break;
        case 7:
            D_801376B4++;
            if (f->speed < D_801376B4) {
                D_801376B4 = 0;
                f->state = 9;
            }
        case 5:
            gDPPipeSync(D_80126BF4++);
            gDPSetPrimColor(D_80126BF4++, 0, 0, 0, 0, 0, 255);
            LOAD4(D_800720C8);
            f->mode = 4;
            break;
        case 8:
            D_801376B4++;
            if (f->speed < D_801376B4) {
                D_801376B4 = 0;
                f->state = 9;
            }
        case 6:
            gDPPipeSync(D_80126BF4++);
            gDPSetPrimColor(D_80126BF4++, 0, 0, 255, 255, 255, 255);
            LOAD4(D_800720A8);
            f->mode = 3;
            break;
        }
    }
    gDPPipeSync(D_80126BF4++);
    gSPEndDisplayList(D_80126BF4++);
}
