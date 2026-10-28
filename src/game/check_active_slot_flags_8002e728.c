typedef struct Slot {
    unsigned short state;
    unsigned short first;
    unsigned short flags;
    unsigned short pad6[4];
} Slot;

extern unsigned char *D_80126BF0;
extern unsigned char D_8013755C;
extern unsigned char D_80137520;
extern void func_8002E894(void);

void func_8002E728(void) {
    int found = 0;
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (((Slot *)(D_80126BF0 + 0x7C8F4))[i].flags & 0x8000) {
            found = 1;
        }
    }
    if (D_8013755C) {
        found = 0;
    }
    if (found) {
        D_80137520 = 25;
        func_8002E894();
    }
}
