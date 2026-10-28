typedef struct Player {
    unsigned char pad[0x24];
    short speed;
    unsigned short state;
} Player;

extern unsigned char D_80136C9D;
extern float D_800708B0[];

float func_80023D1C(Player *player) {
    int speed;

    if (player->state == 1) {
        speed = player->speed < 0 ? -player->speed : player->speed;
        if (speed >= 6) {
            return D_800708B0[D_80136C9D];
        }
    }
    return 1.0f;
}
