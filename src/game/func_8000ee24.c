typedef struct EventRecord {
    unsigned char names[10][9];
    unsigned char countries[10];
    unsigned char medals[10];
    unsigned short medalCounts[3];
    float times[10];
} EventRecord;

extern EventRecord D_801336F8[12];
extern unsigned char D_8006D458[];

void func_8000EE24(unsigned char event, unsigned char *name, unsigned char country, unsigned char medal, float time) {
    short i;
    short k;
    short found = 0;
    float diff;

    if (event != 11) {
    for (i = 0; i < 10; i++) {
        if (time > 0.0f) {
            if (D_801336F8[event].names[i][0] != 0) {
                diff = D_8006D458[event] ? time - D_801336F8[event].times[i] : D_801336F8[event].times[i] - time;
                if (!(diff < 0.0f)) {
                    continue;
                }
            }
            found = 1;
            break;
        }
    }
    if (found) {
        found = i;
        for (i = 9; found < i; i--) {
            for (k = 0; k < 9; k++) {
                D_801336F8[event].names[i][k] = D_801336F8[event].names[i - 1][k];
            }
            D_801336F8[event].countries[i] = D_801336F8[event].countries[i - 1];
            D_801336F8[event].times[i] = D_801336F8[event].times[i - 1];
            D_801336F8[event].medals[i] = D_801336F8[event].medals[i - 1];
        }
        for (k = 0; k < 9; k++) {
            D_801336F8[event].names[found][k] = name[k];
        }
        D_801336F8[event].countries[found] = country;
        D_801336F8[event].times[found] = time;
        D_801336F8[event].medals[found] = medal;
    }
    }
    if (medal < 3) {
        if (D_801336F8[event].medalCounts[medal] < 999) {
            D_801336F8[event].medalCounts[medal]++;
        }
    }
}
