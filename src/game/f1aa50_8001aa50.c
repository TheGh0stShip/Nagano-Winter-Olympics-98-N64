typedef struct Pad {
    unsigned short held;
    unsigned short pressed;
    short stickX;
    short stickY;
    unsigned short repeat;
    unsigned char pad0A[4];
} Pad;

typedef struct Game {
    unsigned char pad0[0x7C8F6];
    Pad pads[4];
} Game;

typedef struct Entry {
    unsigned char pad0[2];
    unsigned short a;
    unsigned short b;
    short busy;
    unsigned char pad8[2];
} Entry;

extern Game *D_80126BF0;
extern unsigned char D_80136190[];
extern Entry D_80136198[][16];
extern void func_8001AB58(unsigned char index);

void func_8001AA50(void) {
    unsigned char i;
    Entry *entry;

    for (i = 0; i < 4; i++) {
        if (D_80126BF0->pads[i].held == 0 && D_80126BF0->pads[i].repeat == 0) {
            continue;
        }
        entry = &D_80136198[i][D_80136190[i]];
        if (entry->busy != 0) {
            continue;
        }
        if (entry->a != 0 || entry->b != 0) {
            func_8001AB58(i);
        }
    }
}
