typedef struct Player {
    unsigned char pad0[0x134];
    short c;
    unsigned char pad136[6];
    short d;
    short b;
    short e;
    short f;
    unsigned char pad144[8];
    short a;
} Player;

extern unsigned char D_80136C9D;
extern signed char D_80071A38[][4];

void func_80027AE0(Player *player, signed char value) {
    switch (value) {
        case -36:
        case -35:
        case -27:
        case -26:
        case -25:
        case -23:
        case -21:
        case -19:
        case -18:
        case -17:
        case -15:
        case -13:
        case -11:
        case -3:
            player->a = 1;
            player->b = 1;
            player->c = 3;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 9:
        case 10:
        case 11:
        case 13:
        case 15:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 23:
        case 25:
        case 26:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 100:
        case 101:
        case 102:
        case 105:
        case 106:
        case 107:
        case 108:
        case 109:
        case 110:
        case 112:
        case 113:
        case 115:
        case 116:
        case 118:
        case 119:
        case 121:
        case 122:
        case 123:
        case 125:
        case 126:
            player->a = 1;
            player->b = 1;
            player->c = 0;
            break;
        case -24:
        case -22:
        case -16:
        case -14:
        case -12:
            player->a = 1;
            player->b = 3;
            player->c = 3;
            break;
        case 12:
        case 14:
        case 16:
        case 22:
        case 24:
        case 111:
        case 114:
        case 117:
        case 120:
            player->a = 1;
            player->b = 3;
            player->c = 0;
            break;
        case 6:
        case 7:
        case 8:
        case 103:
        case 104:
        case 124:
            player->a = 3;
            player->b = 1;
            player->c = 0;
            break;
        default:
            player->a = 1;
            player->b = 3;
            player->c = 0;
            break;
    }
    player->d = 1;
    player->f = 0;
    if (D_80136C9D == 2) {
        player->e = (value < 0 ? -value : value) - 100;
    } else {
        player->e = value < 0 ? -value : value;
    }
}

int func_80027C18(short value) {
    if (value > D_80071A38[D_80136C9D][3]) {
        return 2;
    }
    if (value > D_80071A38[D_80136C9D][2] && value <= D_80071A38[D_80136C9D][3]) {
        return 1;
    }
    if (value >= D_80071A38[D_80136C9D][0] && value <= D_80071A38[D_80136C9D][1]) {
        return -1;
    }
    if (value < D_80071A38[D_80136C9D][0]) {
        return -2;
    }
    return 0;
}
