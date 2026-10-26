typedef struct RuntimeValueTable {
    unsigned char pad[0x190];
    float values[16];
} RuntimeValueTable;

extern RuntimeValueTable D_80137150;
extern float D_801374B8;

void func_8002A948(void) {
    unsigned short i;

    for (i = 0; i < 16; i++) {
        float value = D_80137150.values[i];
        if (!(value < 1000.0f)) {
            if (value < D_801374B8) {
                D_801374B8 = value;
            }
        }
    }
}
