typedef struct Row {
    unsigned char values[7];
} Row;

typedef struct Ranking {
    unsigned char pad[0xA0];
    Row rows[16];
} Ranking;

extern Ranking D_80137150;

unsigned char func_8002A29C(unsigned char column, unsigned char value) {
    unsigned char count = 0;
    unsigned char i;

    for (i = 0; i < 16; i++) {
        if (value < D_80137150.rows[i].values[column]) {
            count++;
        }
    }
    return count;
}
