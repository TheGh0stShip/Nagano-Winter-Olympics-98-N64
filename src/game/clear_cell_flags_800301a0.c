typedef struct Cell {
    unsigned char first[3];
    unsigned char pad3;
    unsigned char second[3];
    unsigned char pad7;
} Cell;

void func_800301A0(Cell *cells) {
    short i;
    short j;

    for (j = 0; j < 3; j++) {
        cells[0].second[j] = 0;
        cells[0].first[j] = 0;
    }
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 3; j++) {
            cells[i * 2 + 1].second[j] = 0;
            cells[i * 2 + 1].first[j] = 0;
        }
    }
}
