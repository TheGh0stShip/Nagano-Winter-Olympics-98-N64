typedef struct Racer {
    unsigned char pad0[5];
    unsigned char item;
    unsigned char mode;
    unsigned char pad7[0x131];
    void *data;
    unsigned char pad13C[0x2EC];
} Racer;

extern unsigned char *D_80126BF0;
extern unsigned char D_80067AC0[];
extern unsigned char D_80067F20[];
extern unsigned char D_80067D50[];
extern unsigned char D_800688D0[];
extern unsigned char D_80068B70[];
extern unsigned char D_80068070[];
extern unsigned char D_800687F0[];
extern unsigned char D_80068650[];
extern unsigned char D_800687A0[];
extern unsigned char D_80068800[];
extern unsigned char D_80068D50[];
extern unsigned char D_80068F70[];

#define RACERS ((Racer *)(D_80126BF0 + 0x802A8))

void func_800061E8(unsigned char mode, unsigned char *list) {
    switch (mode) {
    case 0:
    case 1:
        RACERS[0].mode = mode;
        RACERS[0].item = list[0];
        RACERS[0].data = D_80067AC0;
        break;
    case 2:
    case 3:
        RACERS[0].mode = mode;
        RACERS[0].item = list[0];
        RACERS[0].data = D_80067F20;
        break;
    case 4:
        RACERS[0].mode = mode;
        RACERS[0].item = list[0];
        RACERS[0].data = D_80067D50;
        break;
    case 5:
        RACERS[0].mode = mode;
        RACERS[0].item = list[0];
        RACERS[0].data = D_800688D0;
        break;
    case 6:
        RACERS[0].mode = mode;
        RACERS[0].item = list[0];
        RACERS[0].data = D_80068B70;
        break;
    case 7:
    case 8:
        RACERS[0].mode = RACERS[1].mode = RACERS[2].mode = RACERS[3].mode = mode;
        RACERS[0].item = RACERS[2].item = list[0];
        RACERS[1].item = RACERS[3].item = list[1];
        RACERS[0].data = RACERS[1].data = RACERS[2].data = RACERS[3].data = D_80068070;
        break;
    case 9:
        RACERS[0].mode = RACERS[2].mode = RACERS[1].mode = RACERS[3].mode = RACERS[4].mode =
            RACERS[5].mode = RACERS[6].mode = RACERS[7].mode = mode;
        RACERS[0].item = RACERS[2].item = RACERS[1].item = RACERS[3].item = RACERS[4].item =
            RACERS[5].item = list[0];
        RACERS[0].data = D_800687F0;
        RACERS[1].data = RACERS[2].data = RACERS[3].data = RACERS[4].data = D_80068650;
        RACERS[5].data = D_800687A0;
        break;
    case 10:
        RACERS[0].mode = RACERS[2].mode = mode;
        RACERS[0].item = RACERS[1].item = list[0];
        RACERS[0].data = 0;
        RACERS[1].data = D_80068800;
        break;
    case 11:
        RACERS[0].mode = RACERS[2].mode = RACERS[1].mode = RACERS[3].mode = RACERS[4].mode =
            RACERS[5].mode = mode;
        RACERS[0].item = RACERS[2].item = RACERS[1].item = RACERS[3].item = RACERS[4].item =
            RACERS[5].item = list[0];
        RACERS[0].data = RACERS[1].data = RACERS[2].data = RACERS[3].data = RACERS[4].data =
            RACERS[5].data = D_80068D50;
        break;
    case 12:
        RACERS[0].mode = RACERS[2].mode = RACERS[1].mode = RACERS[3].mode = 12;
        RACERS[0].item = list[0];
        RACERS[1].item = list[1];
        RACERS[2].item = list[2];
        RACERS[3].item = list[3];
        RACERS[0].data = RACERS[1].data = RACERS[2].data = RACERS[3].data = D_80068F70;
        break;
    }
}
