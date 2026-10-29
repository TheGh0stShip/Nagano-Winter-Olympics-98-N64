typedef struct Pad {
    unsigned short connected;
    unsigned short held;
    unsigned short pressed;
    short stick;
    unsigned char pad8[6];
} Pad;

typedef struct Player {
    unsigned char pad0[0x75C4 - 0x7FB28 + 0x7FB28];
} Player;

typedef struct World {
    unsigned char pad0[0x7C8F4];
    Pad pads[4];
} World;

extern World *D_80126BF0;
extern unsigned char D_8013770C[];
extern unsigned char D_8006E590;
extern int D_8007264C[3];
extern unsigned short D_80072A40;
extern int D_801386A4;
extern int func_800349F0(void);
extern void func_80048580(int);

#define NPLAYERS (*((unsigned char *)D_80126BF0 + 0x977F0))
#define PCOLOR(i) (*(int *)((unsigned char *)D_80126BF0 + (i) * 0x138 + 0x875C4))

short func_80033FE8(World *arg0, unsigned char *ready) {
    short ret;
    short i;
    int any;

    if (&arg0);
    ret = 0;
    for (i = 0; i < NPLAYERS; i++) {
        if (D_80126BF0) {}
        if ((D_80126BF0->pads[i].held & 0x200) || (D_80126BF0->pads[i].stick / 16) < 0) {
            if (D_8013770C[i] == 0) {
                if (ready[i] == 1) {
                    func_80048580(0x46A);
                }
                ready[i] = 0;
                goto next;
            }
        }
        if ((D_80126BF0->pads[i].held & 0x100) || (D_80126BF0->pads[i].stick / 16) > 0) {
            if (D_8013770C[i] == 0) {
                if (ready[i] == 0) {
                    func_80048580(0x46A);
                }
                ready[i] = 1;
            }
        }
next:
        if ((D_80126BF0->pads[i].pressed & 0x8000) && D_8013770C[i] == 0) {
            func_80048580(0x468);
            D_8013770C[i] = 1;
            if (ready[i] == 0) {
                D_8006E590 |= 1 << i;
            } else {
                D_8006E590 &= (1 << i) ^ 0xFF;
            }
        } else if ((D_80126BF0->pads[i].pressed & 0x4000) && D_8013770C[i] == 1) {
            func_80048580(0x46B);
            D_8013770C[i] = 0;
        }
        if (D_8013770C[i] == 0 && ((D_80072A40 % 24) / 12 != 0 || D_80126BF0->pads[i].connected == 0)) {
            PCOLOR(i) = D_8007264C[0];
        } else if (ready[i] == 0) {
            PCOLOR(i) = D_8007264C[1];
        } else {
            PCOLOR(i) = D_8007264C[2];
        }
    }
    any = 0;
    for (i = 0; i < NPLAYERS; i++) {
        if (D_8013770C[i] == 0 || D_80126BF0->pads[i].connected == 0) {
            any = 1;
            break;
        }
    }
    if (any == 0) {
        any = 0;
        for (i = 0; i < NPLAYERS; i++) {
            if (ready[i] != 0) {
                any = 1;
            }
        }
        if (any == 0 && func_800349F0() == 0) {
            func_80048580(7);
            D_801386A4 = 0;
        }
        ret = 1;
    }
    D_80072A40++;
    return ret;
}
