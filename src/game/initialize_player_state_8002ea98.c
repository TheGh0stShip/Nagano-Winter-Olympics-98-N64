typedef struct PlayerState {
    unsigned char pad0[0x13C];
    unsigned short state;
    short mode;
    unsigned short value;
    unsigned char pad142[0xA];
    unsigned short timer;
    unsigned char pad14E[0x2DA];
} PlayerState;

extern unsigned char *D_80126BF0;
extern unsigned short D_80071F1C[];

extern void func_8002EBD0(unsigned char index);

void func_8002EA98(unsigned char index) {
    PlayerState *player = (PlayerState *)(D_80126BF0 + 0x802A8) + index;

    if (player->state == 2) {
        player->value = D_80071F1C[(int)index];
        player->state = 1;
        player->mode = 3;
        player->timer = 1;
        func_8002EBD0(index);
        if ((int)index == 3) {
            player->timer = 2;
        }
    }
}
