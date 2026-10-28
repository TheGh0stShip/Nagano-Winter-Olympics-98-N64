typedef struct Entry {
    unsigned char pad0[0x10];
    short value;
    unsigned char pad12[2];
} Entry;

typedef struct Pool {
    unsigned char count;
    unsigned char limit;
} Pool;

extern Pool D_80131920;
extern Entry D_80131940[];

int func_8000A8EC(unsigned char count) {
    short i;

    if (count < 301) {
        if (count < D_80131920.count) {
            for (i = count; i < D_80131920.count; i++) {
                D_80131940[i].value = 0;
            }
            D_80131920.limit = count;
        }
        D_80131920.count = count;
    } else {
        return 1;
    }
    return 0;
}
