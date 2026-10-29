typedef struct Player {
    unsigned char pad0[0x140];
    unsigned short state;
} Player;

extern unsigned char D_80136C9D;

int func_80024478(Player *player) {
    int result = 0;

    switch (D_80136C9D) {
    case 0:
        if (player->state == 36 || player->state == -36 || player->state == 37 || player->state == 39 || player->state == 38) {
            result = 1;
        }
        break;
    case 1:
        if (player->state == 3 || player->state == -3 || player->state == 4 || player->state == 9 || player->state == 5) {
            result = 1;
        }
        break;
    default:
        if (player->state == 6 || player->state == 5 || player->state == 8 || player->state == 7 || player->state == 9) {
            result = 1;
        }
        break;
    }
    return result;
}
