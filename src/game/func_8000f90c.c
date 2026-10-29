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

extern EventRecord D_801336F8[12];
extern EventTotals D_80133E48;

int func_8000F90C(void) {
    short i;

    for (i = 0; i < 12; i++) {
        if (D_801336F8[i].scores[0] == 0) {
            return 0;
        }
    }
    if (D_80133E48.scores[0] == 0) {
        return 0;
    }
    for (i = 0; i < 12; i++) {
        if (D_801336F8[i].scores[1] == 0) {
            return 1;
        }
    }
    if (D_80133E48.scores[1] == 0) {
        return 1;
    }
    for (i = 0; i < 12; i++) {
        if (D_801336F8[i].scores[2] == 0) {
            return 1;
        }
    }
    if (D_80133E48.scores[2] == 0) {
        return 1;
    }
    return 2;
}
