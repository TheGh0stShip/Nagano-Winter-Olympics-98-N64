#include "PR/ultratypes.h"
#include "PR/mbi.h"

typedef struct ContStatus {
    unsigned short type;
    unsigned char status;
    unsigned char errnum;
} ContStatus;

typedef struct Pfs {
    unsigned char pad[0x68];
} Pfs;

typedef struct FileState {
    unsigned int file_size;
    unsigned int game_code;
    unsigned short company_code;
    unsigned char ext_name[4];
    unsigned char game_name[16];
} FileState;

extern char *D_80126BF0;
extern Gfx *D_80126BF4;
extern signed char D_80135720;
extern signed char D_80135721;
extern unsigned short D_80135724;
extern unsigned short D_80135728;
extern unsigned char D_8013572C;
extern unsigned char D_8013572D;
extern short D_8013572E;
extern unsigned char D_80135730;
extern unsigned char D_80135731;
extern unsigned char D_80135732;
extern unsigned char D_80135733;
extern unsigned char D_80135734;
extern int D_80135738;
extern int D_8013573C;
extern int D_80135740;
extern unsigned char D_80135744[];
extern int D_80135748[];
extern ContStatus D_80135370[];
extern FileState D_80135380[];
extern Pfs D_80135580[];
extern Gfx D_8006EE10[];
extern Gfx D_8006EE78[];
extern Gfx D_8006EEA0[];

extern int func_800517F0(Pfs *, unsigned short, unsigned int, unsigned char *, unsigned char *);
extern int func_8005C900(Pfs *, int *, int *);
extern int func_8005CA60(Pfs *, int, FileState *);
extern int func_8004E3F0(Pfs *, int *);
extern void func_800163B8(void);
extern void func_800138F0(ContStatus *);
extern void func_80015430(Gfx **list, void *tex, unsigned char *text, unsigned char count, int x, unsigned int y, int palette);
extern void func_800160B4(Gfx **list, void *tex, unsigned int s, int t, int xl, int yl, int xh, int yh, int palette);
extern void func_80015E24(Gfx **list, void *tex, unsigned int uls, int ult, int xl, unsigned int yl, int xh, int yh, int palette);
extern void func_8001577C(Gfx **list, void *tex, unsigned short value, int x, unsigned int y, int palette);
extern void func_80015B98(Gfx **list, void *tex, unsigned int uls, int ult, unsigned int xl, unsigned int yl, int xh, int yh, int palette);

#define GFX(list, a, b) { Gfx *_g = (*(list))++; _g->words.w1 = (b); _g->words.w0 = (a); }

int func_80014164(Gfx **list, void *tex) {
    unsigned char mark = 60;
    unsigned char i;
    void *texIcons;
    int y;
    int highlight;

    D_8013572C++;
    if (*(unsigned short *)(D_80126BF0 + 0x78000 + 0 * 14 + 0x48F8) == 0x8000 && D_8013572D == 0) {
        switch (D_80135732) {
        case 0:
        case 3:
            if (D_80135721 == 16) {
                D_8013572D = 2;
            } else {
                D_80135732 = 1;
                D_80135734 = 1;
            }
            break;
        case 1:
            if (D_80135734 == 0) {
                if (func_800517F0(&D_80135580[D_80135720], D_80135380[D_80135721].company_code,
                                  D_80135380[D_80135721].game_code, D_80135380[D_80135721].game_name,
                                  D_80135380[D_80135721].ext_name) != 0) {
                    D_80135732 = 2;
                }
                D_80135721 = 16;
                D_80135730 = 1;
                D_80135732 = 0;
            } else {
                D_80135732 = 0;
            }
            break;
        case 2:
        case 4:
            D_80135732 = 0;
            break;
        }
    }
    if (D_8013572D == 0) {
        func_800163B8();
        switch (D_80135732) {
        case 0:
        case 3:
            if ((*(unsigned short *)(D_80126BF0 + 0x78000 + 0 * 14 + 0x48F8) | D_80135724) & 0x200) {
                D_80135720--;
                D_80135730 = 1;
                D_80135731 = 0;
                D_80135732 = 0;
                D_80135733 = 0;
            }
            if ((*(unsigned short *)(D_80126BF0 + 0x78000 + 0 * 14 + 0x48F8) | D_80135724) & 0x100) {
                D_80135720++;
                D_80135730 = 1;
                D_80135731 = 0;
                D_80135732 = 0;
                D_80135733 = 0;
            }
            break;
        case 1:
            if ((*(unsigned short *)(D_80126BF0 + 0x78000 + 0 * 14 + 0x48F8) | D_80135724) & 0x300) {
                D_80135734 ^= 1;
            }
            break;
        case 2:
        case 4:
            break;
        }
    }
    if (D_80135720 < 0) {
        D_80135720 = 3;
    }
    if (D_80135720 >= 4) {
        D_80135720 = 0;
    }
    func_800138F0(D_80135370);
    for (i = 0; i < 4; i++) {
        if (D_80135370[i].status & 2) {
            D_80135744[i] = 1;
        }
    }
    if (D_80135370[D_80135720].status & 1) {
        D_80135731 = 0;
        y = func_8005C900(&D_80135580[D_80135720], &D_8013573C, &D_80135740);
        if (y == 4 || y == 3) {
            if (D_80135733 == 0) {
                D_80135730 = 1;
                D_80135721 = 16;
                D_80135732 = 4;
                D_80135731 = 1;
                D_80135733 = 1;
            }
        }
        if (y == 2) {
            D_80135744[D_80135720] = 1;
        }
        if (D_80135744[D_80135720] != 0) {
            D_80135730 = 1;
            D_80135721 = 16;
            D_80135732 = 3;
            D_80135731 = 1;
        }
    } else {
        D_80135730 = 1;
        D_80135721 = 16;
        D_80135732 = 0;
        D_80135731 = 1;
    }
    if (D_80135731 == 0) {
        if (D_80135730 != 0) {
            for (i = 0; i < 16; i++) {
                D_80135748[i] = func_8005CA60(&D_80135580[D_80135720], i, &D_80135380[i]);
            }
            D_80135730 = 0;
            func_8004E3F0(&D_80135580[D_80135720], &D_80135738);
            if (D_80135721 < 16 && D_80135748[D_80135721] != 0) {
                D_80135721 = 16;
            }
        }
        if (D_8013572D == 0 && D_80135732 == 0) {
            if (D_80135728 & 0x800) {
                D_80135721--;
                if (D_80135721 < 0) {
                    D_80135721 = 16;
                } else {
                    while (D_80135748[D_80135721] != 0) {
                        D_80135721--;
                        if (D_80135721 < 0) {
                            D_80135721 = 16;
                            break;
                        }
                    }
                }
            }
            if (D_80135728 & 0x400) {
                D_80135721++;
                if (D_80135721 > 16) {
                    D_80135721 = 0;
                }
                if (D_80135721 != 16) {
                    while (D_80135748[D_80135721] != 0) {
                        D_80135721++;
                        if (D_80135721 >= 16) {
                            D_80135721 = 16;
                            break;
                        }
                    }
                }
            }
        }
    }

    gSPDisplayList((*list)++, D_8006EE10);
    gSPDisplayList((*list)++, D_8006EE78);
    gDPSetTextureImage((*list)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, tex);
    gDPTileSync((*list)++);
    gDPSetTile((*list)++, 0, 0, 0, 256, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
    gDPLoadSync((*list)++);
    gDPLoadTLUTCmd((*list)++, G_TX_LOADTILE, 255);
    gDPPipeSync((*list)++);

    func_80015E24(list, (char *)tex + 0x6600, 0x60, 0x60, 0, 0, 0x13F, 0xEF, 5);
    texIcons = (char *)tex + 0x4600;
    func_80015E24(list, texIcons, 0, 0x60, 0x16, 0xE, 0x35, 0x2D, 7);
    func_800160B4(list, (char *)tex + 0x8600, 0x40, 0, 0x66, 0x15, 0x9D, 0x2C, 2);
    func_800160B4(list, (char *)tex + 0x8600, 0, 0x20, 0xA7, 0xC, 0xEE, 0x33, 4);
    func_80015E24(list, texIcons, 0x20, 0x40, 0xC6, 0x10, 0xE5, 0x2F, 1);
    func_800160B4(list, texIcons, 0x40, 0x40, 0x3C, 0x2D, 0x7B, 0x3C, 0);
    func_800160B4(list, texIcons, 0x40, 0x60, 0xFC, 0x2D, 0x13B, 0x3C, 0);
    func_80015E24(list, texIcons, 0, 0x40, 0xE2, 0xDA, 0x101, 0xE9, 0);

    for (i = 0; i < 16; i++) {
        highlight = (D_80135721 == i) ? 8 : 0;
        func_80015B98(list, texIcons, (i * 16) & 0x7F, (i & 8) * 2, 0x1F, i * 10 + 0x3A, 0x2E, i * 10 + 0x43, highlight);
    }
    highlight = (D_80135721 == i) ? 8 : 0;
    func_80015E24(list, texIcons, 0x20, 0x60, 0x1F, i * 10 + 0x3A, 0x3E, i * 10 + 0x49, highlight);

    if (D_80135731 == 0) {
        for (i = 0; i < 16; i++) {
            if (D_80135748[i] == 0) {
                highlight = (D_80135721 == i) ? 8 : 0;
                func_80015430(list, tex, D_80135380[i].game_name, 16, 0x2C, i * 10 + 0x3A, highlight);
                if (D_80135380[i].ext_name[0] != 0 || D_80135380[i].ext_name[1] != 0 || D_80135380[i].ext_name[2] != 0 ||
                    D_80135380[i].ext_name[3] != 0) {
                    func_80015430(list, tex, &mark, 1, 0xCC, i * 10 + 0x3A, highlight);
                }
                func_80015430(list, tex, D_80135380[i].ext_name, 4, 0xD6, i * 10 + 0x3A, highlight);
                func_8001577C(list, tex, (unsigned short)(D_80135380[i].file_size + 0xFF) >> 8, 0x108, i * 10 + 0x3A, highlight);
            }
        }
        func_8001577C(list, tex, *(unsigned short *)((char *)&D_80135738 + 2) >> 8, 0x104, 0xDA, 0);
    }

    func_80015B98(list, texIcons, 0x10, 0x30, 0x14, D_80135721 * 10 + 0x3C, 0x23, D_80135721 * 10 + 0x45, 1);
    if (D_8013572C & 4) {
        i = D_80135720 * 6 + 0x71;
        if (D_80135720 >= 2) {
            i += 8;
        }
        func_80015B98(list, texIcons, 0, 0x30, i, 0x20, i + 0xF, 0x2F, 1);
    }
    func_80015B98(list, texIcons, D_80135720 * 16, 0x20, 0xB4, 0x11, 0xC3, 0x20, 1);
    func_80015B98(list, texIcons, D_80135720 * 16 + 0x40, 0x70, 0xB4, 0x21, 0xC3, 0x30, 1);
    if (D_80135370[D_80135720].errnum & 8) {
        func_80015B98(list, texIcons, 0x70, 0x20, 0xCA, 0x15, 0xD9, 0x24, 1);
    } else if (!(D_80135370[D_80135720].status & 1) || D_80135744[D_80135720] != 0) {
        func_80015B98(list, texIcons, 0x60, 0x20, 0xCB, 0xF, 0xDA, 0x1E, 1);
    }

    if (D_80135732 == 1) {
        if (D_80135721 < 5 || D_80135721 >= 13) {
            y = 0x6A;
        } else if (D_80135721 >= 9) {
            y = 0x44;
        } else {
            y = 0x90;
        }
        gSPDisplayList((*list)++, D_8006EEA0);
        gDPSetPrimColor(D_80126BF4++, 0, 0, 255, 255, 255, 224);
        func_80015B98(list, (char *)tex + 0x6600, 0x40, 0x40, 0x40, y, 0xFF, y + 0x3F, 1);
        gSPDisplayList((*list)++, D_8006EE78);
        func_800160B4(list, (char *)tex + 0x8600, 0, 0, 0x88, y + 8, 0xB7, y + 0x17, 6);
        func_800160B4(list, (char *)tex + 0x6600, 0, 0, 0x40, y, 0xBF, y + 0x3F, 1);
        func_800160B4(list, (char *)tex + 0x6600, 0, 0x40, 0xC0, y, 0xFF, y + 0x3F, 1);
        func_80015B98(list, texIcons, 0x20, 0x30, (D_80135734 << 6) + 0x60, y + 0x28, (D_80135734 << 6) + 0x6F,
                      y + 0x37, 1);
    }
    if (D_80135732 == 2) {
        gSPDisplayList((*list)++, D_8006EEA0);
        gDPSetPrimColor(D_80126BF4++, 0, 0, 255, 255, 255, 224);
        func_80015B98(list, (char *)tex + 0x6600, 0x40, 0x40, 0x30, 0x70, 0x10F, 0x97, 1);
        gSPDisplayList((*list)++, D_8006EE78);
        func_800160B4(list, (char *)tex + 0x9800, 0, 0, 0x30, 0x70, 0xAF, 0x97, 1);
        func_800160B4(list, (char *)tex + 0x9800, 0, 0x40, 0xB0, 0x70, 0x10F, 0x97, 1);
    }
    if (D_80135732 == 4) {
        gSPDisplayList((*list)++, D_8006EEA0);
        gDPSetPrimColor(D_80126BF4++, 0, 0, 255, 255, 255, 224);
        func_80015B98(list, (char *)tex + 0x6600, 0x40, 0x40, 0x34, 0x70, 0x10B, 0x97, 1);
        gSPDisplayList((*list)++, D_8006EE78);
        func_800160B4(list, (char *)tex + 0xCC00, 0, 0, 0x34, 0x70, 0xB3, 0x97, 1);
        func_800160B4(list, (char *)tex + 0xCC00, 0, 0x40, 0xB4, 0x70, 0x10B, 0x97, 1);
    }
    if (D_8013572D == 1) {
        gSPDisplayList((*list)++, D_8006EEA0);
        gDPSetPrimColor(D_80126BF4++, 0, 0, 255, 255, 255, D_8013572E);
        func_80015B98(list, texIcons, 0x30, 0x70, 0, 0, 0x13F, 0xEF, 0);
        D_8013572E -= 8;
        if (D_8013572E <= 0) {
            D_8013572D = 0;
            D_8013572E = 0;
        }
    }
    if (D_8013572D == 2) {
        gSPDisplayList((*list)++, D_8006EEA0);
        gDPSetPrimColor(D_80126BF4++, 0, 0, 255, 255, 255, D_8013572E);
        func_80015B98(list, texIcons, 0x30, 0x70, 0, 0, 0x13F, 0xEF, 0);
        if (D_8013572E == 0xFF) {
            return 1;
        }
        D_8013572E += 8;
        if (D_8013572E >= 0xFF) {
            D_8013572E = 0xFF;
        }
    }
    return 0;
}
