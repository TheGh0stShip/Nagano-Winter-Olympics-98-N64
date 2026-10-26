typedef struct RuntimeValueTable {
    unsigned char pad[0x180];
    unsigned char active[16];
    float values[16];
} RuntimeValueTable;

extern RuntimeValueTable D_80137150;

void func_80028264(float amount) {
    unsigned short i;

    for (i = 0; i < 16; i++) {
        if (D_80137150.active[i] != 0) {
            D_80137150.values[i] += amount;
        }
    }
}
