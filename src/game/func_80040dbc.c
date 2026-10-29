typedef struct { unsigned char b[0x7CC]; } Slot;
extern Slot *D_800730A8;

int func_80040DBC(unsigned char idx) {
    int result = 0;
    int i;
    Slot *p = &D_800730A8[idx];

    for (i = 0; i < sizeof(Slot); i++) {
        if (p->b[i] != D_800730A8[4].b[i]) {
            result = 1;
            break;
        }
    }
    return result;
}
