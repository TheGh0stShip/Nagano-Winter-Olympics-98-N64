typedef struct Item {
    unsigned char pad[8];
    int id;
} Item;

typedef struct Player {
    short state;
    unsigned char pad[0x426];
} Player;

extern unsigned char *D_80126BF0;
extern int func_80005E70(int id);
extern void func_8000C190(int id);
extern void func_800090CC(short player, unsigned char kind, Item *item);

void func_80007EC8(unsigned short player, Item *item) {
    struct {
        int kind;
        int other;
    } info;

    if (func_80005E70(item->id)) {
        func_8000C190(item->id);
    }
    func_800090CC(player, info.kind, item);
    ((Player *)(D_80126BF0 + 0x802A8))[player].state = 3;
}
