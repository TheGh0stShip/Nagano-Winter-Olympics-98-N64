typedef struct PlayerSpeedState {
    unsigned char pad0[0x24];
    short speed;
    unsigned char pad26[0x2E];
    unsigned short state;
} PlayerSpeedState;

extern unsigned char D_80136C9D;
extern float D_8007FC24;
extern float func_80023D1C(PlayerSpeedState *);

float func_80023D7C(PlayerSpeedState *player) {
    float value = player->speed * -1.0f;

    switch (D_80136C9D) {
        case 1:
            value *= D_8007FC24;
            break;
        case 2:
            value *= 2.2f;
            break;
    }
    if (player->state == 1) {
        value *= 1.5f;
    }
    value = (double)value * 0.05;
    value *= func_80023D1C(player);
    return value;
}
