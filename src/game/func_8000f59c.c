typedef struct EventRecord {
    unsigned char names[10][9];
    unsigned char countries[10];
    unsigned char medals[10];
    unsigned short medalCounts[3];
    float times[10];
} EventRecord;

typedef struct EventTotals {
    unsigned char names[10][9];
    unsigned char countries[10];
    unsigned char medals[10][8];
    unsigned char scores[10][7];
    unsigned short medalCounts[3];
} EventTotals;

typedef struct NameEntry {
    unsigned char text[9];
} NameEntry;

extern unsigned char D_80133F48;
extern unsigned char D_801335E0;
extern EventRecord D_801336F8[12];
extern EventTotals D_80133E48;
extern NameEntry D_801376D8[4];
extern unsigned char D_8006D450;

void func_8000F59C(void) {
    short i;
    short j;
    short k;

    D_80133F48 = 0;
    D_801335E0 = 0;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 9; k++) {
                D_801336F8[i].names[j][k] = 0;
            }
            D_801336F8[i].countries[j] = 0;
            D_801336F8[i].medals[j] = 15;
            D_801336F8[i].times[j] = j;
        }
        for (j = 0; j < 3; j++) {
            D_801336F8[i].medalCounts[j] = 0;
        }
    }
    for (j = 0; j < 3; j++) {
        D_801336F8[11].medalCounts[j] = 0;
    }
    for (j = 0; j < 10; j++) {
        for (i = 0; i < 9; i++) {
            D_80133E48.names[j][i] = 0;
        }
        D_80133E48.countries[j] = 0;
        for (i = 0; i < 8; i++) {
            D_80133E48.medals[j][i] = 15;
        }
        for (i = 0; i < 8; i++) {
            D_80133E48.scores[j][i] = (float)j;
        }
    }
    for (j = 0; j < 3; j++) {
        D_80133E48.medalCounts[j] = 0;
    }
    for (j = 0; j < 4; j++) {
        D_801376D8[j].text[0] = 0;
    }
    D_8006D450 = 0;
}
