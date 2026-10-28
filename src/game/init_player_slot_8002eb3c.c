typedef struct Player { unsigned char pad0[0x13C]; short a; short b; unsigned short c; unsigned char pad142[0xA]; short d; unsigned char pad14E[0x2DA]; } Player;
extern unsigned char *D_80126BF0;
extern unsigned short D_80071F14[];
extern void func_8002EBD0(unsigned char index);
void func_8002EB3C(unsigned char index) {
    Player *player = (Player *)(D_80126BF0 + 0x802A8) + index;
    player->d = 1;
    player->a = 1;
    player->b = 1;
    player->c = D_80071F14[(int)index];
    func_8002EBD0(index);
    if ((int)index == 3) { player->d = 2; }
}
