typedef struct Item { int id; int kind; } Item;
typedef struct Pair { int owner; Item *item; } Pair;
extern unsigned char D_8006C3EC;
extern Pair D_801317C8[];

void func_80007F90(int owner, Item *item) {
    int found = 0;
    Pair *pair;
    unsigned char i;

    if (item->kind == 1) {
        pair = D_801317C8;
        for (i = 0; i < D_8006C3EC; i++, pair++) {
            if (owner == pair->owner && item == pair->item) {
                found = 1;
                break;
            }
        }
        if (!found) {
            pair->owner = owner;
            pair->item = item;
            D_8006C3EC++;
        }
    }
}
