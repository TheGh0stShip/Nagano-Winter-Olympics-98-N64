typedef struct Pair {
    int x;
    int y;
} Pair;

typedef struct Slot {
    int v;
    unsigned char pad[0x134];
} Slot;

extern unsigned char *D_80126BF0;
extern signed char D_80138220[];
extern Pair D_800721A4[];
extern Pair D_800721E4[];
extern Pair D_80072204[][4];

void func_8003FD74(void) {
    short i;
    Slot *slots;

    for (i = 0; i < 4; i++) {
        if (D_80138220[i * 2] < 0) {
            if (D_80138220[i * 2 + 1] == 0) {
                ((Slot *)(D_80126BF0 + 0x84024))[i * 2].v = D_800721E4[-D_80138220[i * 2] - 1].x;
                ((Slot *)(D_80126BF0 + 0x84024))[i * 2 + 1].v = D_800721E4[-D_80138220[i * 2] - 1].y;
            } else {
                ((Slot *)(D_80126BF0 + 0x84024))[i * 2].v = D_80072204[D_80138220[i * 2 + 1]][-D_80138220[i * 2] + 7].x;
                ((Slot *)(D_80126BF0 + 0x84024))[i * 2 + 1].v = D_80072204[D_80138220[i * 2 + 1]][-D_80138220[i * 2] + 7].y;
            }
        } else {
            if (D_80138220[i * 2 + 1] == 0) {
                ((Slot *)(D_80126BF0 + 0x84024))[i * 2].v = D_800721A4[D_80138220[i * 2]].x;
                ((Slot *)(D_80126BF0 + 0x84024))[i * 2 + 1].v = D_800721A4[D_80138220[i * 2]].y;
            } else {
                ((Slot *)(D_80126BF0 + 0x84024))[i * 2].v = D_80072204[D_80138220[i * 2 + 1]][D_80138220[i * 2] - 4].x;
                ((Slot *)(D_80126BF0 + 0x84024))[i * 2 + 1].v = D_80072204[D_80138220[i * 2 + 1]][D_80138220[i * 2] - 4].y;
            }
        }
    }
}
