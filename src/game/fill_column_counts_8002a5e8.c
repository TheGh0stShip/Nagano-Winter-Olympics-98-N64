typedef struct Row {
    unsigned char values[7];
} Row;

typedef struct Ranking {
    unsigned char pad[0xA2];
    Row rows[16];
} Ranking;

extern Ranking D_801373A0;
extern unsigned char func_8002A660(unsigned char column, unsigned char value);

void func_8002A5E8(unsigned char row, unsigned char *out) {
    unsigned char i;

    for (i = 0; i < 7; i++) {
        out[i] = func_8002A660(i, D_801373A0.rows[row].values[i]);
    }
}
