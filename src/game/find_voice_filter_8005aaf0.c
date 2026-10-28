typedef struct Filter {
    unsigned char data[0x2C];
} Filter;

typedef struct Voice {
    unsigned char pad0[0x20];
    Filter filters[1];
    unsigned char pad4C[0];
} Voice;

typedef struct Source {
    unsigned char pad0[0x10];
    int type;
} Source;

typedef struct Chain {
    Source *first;
} Chain;

typedef struct Synth {
    unsigned char pad0[0x1C];
    Chain *chain;
} Synth;

typedef struct Player {
    unsigned char pad0[0x30];
    Synth *synth;
    unsigned char *voices;
} Player;

Filter *func_8005AAF0(Player *player, short voice, short index) {
    Synth *synth = player->synth;
    Chain *chain = synth->chain;

    if (chain->first->type == 5) {
        return (Filter *)(player->voices + voice * 0x4C + 0x20) + index;
    }
    return 0;
}
