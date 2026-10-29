typedef struct EventRecord {
    unsigned char active;
    unsigned char pad1[0x6D];
    unsigned short scores[3];
    unsigned char pad74[0x9C - 0x74];
} EventRecord;

typedef struct EventTotals {
    unsigned char active;
    unsigned char pad1[0xF9];
    unsigned short scores[3];
} EventTotals;

extern unsigned char D_80133F48;
extern unsigned char D_801335E0;
extern EventRecord D_801336F8[12];
extern EventTotals D_80133E48;

int func_8000F840(void) {
    short i;

    if (D_80133F48) {
        return 0;
    }
    if (D_801335E0) {
        return 0;
    }
    for (i = 0; i < 11; i++) {
        if (D_801336F8[i].active) {
            return 0;
        }
    }
    for (i = 0; i < 3; i++) {
        if (D_801336F8[11].scores[i]) {
            return 0;
        }
    }
    if (D_80133E48.active) {
        return 0;
    }
    return 1;
}
