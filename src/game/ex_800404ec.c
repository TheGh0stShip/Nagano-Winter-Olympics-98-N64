typedef struct SaveSlot {
    unsigned char data[0x7CC];
} SaveSlot;

extern unsigned char *D_80126BF0;
extern SaveSlot *D_800730A8;
extern void func_800407C0(signed char *);

void func_800404EC(signed char *out) {
    short i;
    short j;
    signed char found;

    D_800730A8 = (SaveSlot *)(D_80126BF0 + 0x92C78);
    func_800407C0(out);
    found = 0;
    for (i = 0; i < 4; i++) {
        if (((D_800730A8[i].data[0] >> 2) & 1) == 0) {
            out[i] = -(i + 1);
        }
    }
    if (((D_800730A8[0].data[0] >> 2) & 1) == 1) {
        out[0] = 0;
    }
    for (i = 1; i < 4; i++) {
        if (((D_800730A8[i].data[0] >> 2) & 1) == 1) {
            for (j = 0; j < i; j++) {
                found = 0;
                if (((D_800730A8[j].data[0] >> 2) & 1) == 1 && (D_800730A8[j].data[0] & 3) == (D_800730A8[i].data[0] & 3)) {
                    out[i] = out[j];
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                out[i] = i;
            }
        }
    }
}
