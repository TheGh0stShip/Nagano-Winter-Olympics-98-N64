typedef struct Table {
    unsigned char names[24][9];
    unsigned char first[24];
    unsigned char second[24];
    float values[24];
} Table;

void func_80028D7C(Table *table) {
    unsigned short i;
    unsigned short j;

    for (i = 0; i < 24; i++) {
        for (j = 0; j < 9; j++) {
            table->names[i][j] = ' ';
        }
        table->first[i] = 0;
        table->values[i] = 0.0f;
        table->second[i] = 0;
    }
}
