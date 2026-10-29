typedef struct EventTotals {
    unsigned char names[10][9];
    unsigned char countries[10];
    unsigned char medals[10][8];
    unsigned char scores[10][7];
    unsigned short medalCounts[3];
} EventTotals;

extern EventTotals D_80133E48;

void func_8000F04C(unsigned char *name, unsigned char country, unsigned char *medals, unsigned char *scores) {
    short i;
    short j;
    short found = 0;
    unsigned short total;
    unsigned short newTotal;

    for (i = 0; i < 10; i++) {
        total = 0;
        newTotal = 0;
        for (j = 0; j < 7; j++) {
            total += D_80133E48.scores[i][j];
            newTotal += scores[j];
        }
        if (total < newTotal) {
            found = 1;
            break;
        }
    }
    if (found) {
        found = i;
        for (i = 9; found < i; i--) {
            for (j = 0; j < 9; j++) {
                D_80133E48.names[i][j] = D_80133E48.names[i - 1][j];
            }
            D_80133E48.countries[i] = D_80133E48.countries[i - 1];
            for (j = 0; j < 7; j++) {
                D_80133E48.scores[i][j] = D_80133E48.scores[i - 1][j];
            }
            for (j = 0; j < 8; j++) {
                D_80133E48.medals[i][j] = D_80133E48.medals[i - 1][j];
            }
        }
        for (j = 0; j < 9; j++) {
            D_80133E48.names[found][j] = name[j];
        }
        D_80133E48.countries[found] = country;
        for (j = 0; j < 7; j++) {
            D_80133E48.scores[found][j] = scores[j];
        }
        for (j = 0; j < 8; j++) {
            D_80133E48.medals[found][j] = medals[j];
        }
    }
    if (medals[7] < 3) {
        if (D_80133E48.medalCounts[medals[7]] < 999) {
            D_80133E48.medalCounts[medals[7]]++;
        }
    }
}
