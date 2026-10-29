typedef struct Player {
    unsigned char pad[0x24];
    short speed;
    unsigned short state;
} Player;

extern unsigned char D_80136C9D;

extern float D_8007FC38;
extern float D_8007FC3C;
extern float D_8007FC40;
extern double D_8007FC48;
extern double D_8007FC50;
extern double D_8007FC58;
float func_80023E3C(Player *player) {
    int speed;
    float drag;
    float result;

    if (player->state == 1 && (player->speed < 0 ? -player->speed : player->speed) >= 6) {
        switch (D_80136C9D) {
        case 1: result = D_8007FC3C; break;
        case 2: result = D_8007FC40; break;
        default: result = D_8007FC38; break;
        }
    } else {
        switch (D_80136C9D) {
        case 1:
            speed = player->speed < 0 ? -player->speed : player->speed;
            drag = speed * D_8007FC48;
            break;
        case 2:
            speed = player->speed < 0 ? -player->speed : player->speed;
            drag = speed * D_8007FC50;
            break;
        default:
            speed = player->speed < 0 ? -player->speed : player->speed;
            drag = speed * D_8007FC58;
            break;
        }
        result = 1.0f - drag;
    }
    result = (double)result;
    return result;
}
