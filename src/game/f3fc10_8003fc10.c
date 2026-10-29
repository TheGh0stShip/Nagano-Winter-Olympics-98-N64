typedef struct Pair {
    signed char value;
    signed char extra;
} Pair;

extern Pair D_80138220[];

void func_8003FC10(unsigned char lo, unsigned char hi, unsigned char *out) {
    short i;
    int found;

    *out = 1 << lo;
    if (lo < hi) {
        for (i = lo + 1; i < 4; i++) {
            if (D_80138220[i].value == D_80138220[hi].value) {
                *out |= 1 << i;
            }
        }
    }
    found = 0;
    if (lo > 0) {
        for (i = 0; i < lo; i++) {
            if (D_80138220[i].value == D_80138220[lo].value) {
                found = 1;
                break;
            }
        }
    }
    if (found == 0) {
        for (i = lo; i < 4; i++) {
            if (D_80138220[i].value == D_80138220[lo].value) {
                *out |= 1 << i;
            }
        }
    }
}
