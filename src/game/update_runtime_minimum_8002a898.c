typedef struct RuntimeValueTable {
    unsigned char pad0[0x1D0];
    float first[16];
    float second[16];
} RuntimeValueTable;

extern RuntimeValueTable D_80137150;
extern float D_801374B8;

void func_8002A898(void) {
    unsigned short i;

    for (i = 0; i < 16; i++) {
        float value = D_80137150.first[i];

        if (!(value < 1000.0f)) {
            if (value < D_801374B8) {
                D_801374B8 = value;
            }
        }
    }
    for (i = 0; i < 16; i++) {
        float value = D_80137150.second[i];

        if (!(value < 1000.0f)) {
            if (value < D_801374B8) {
                D_801374B8 = value;
            }
        }
    }
}
