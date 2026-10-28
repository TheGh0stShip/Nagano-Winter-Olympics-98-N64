typedef struct Row {
    unsigned char values[7];
} Row;

typedef struct Ranking {
    unsigned char pad[0xA2];
    Row rows[16];
} Ranking;

extern Ranking D_801373A0;

unsigned char func_8002A660(unsigned char column, unsigned char value) {
    unsigned char count = 0;
    unsigned char i;

    for (i = 0; i < 16; i++) {
        if (value < D_801373A0.rows[i].values[column]) {
            count++;
        }
    }
    return count;
}
