typedef struct RuntimeIndexTable {
    unsigned char pad[0x180];
    unsigned char values[16];
} RuntimeIndexTable;

extern RuntimeIndexTable D_80137150;

unsigned char func_8002B5D0(unsigned char current) {
    unsigned char result = 0;
    unsigned char i;
    unsigned char target = current + 1;

    for (i = 0; i < 16; i++) {
        if (D_80137150.values[i] == target) {
            result = i;
            break;
        }
    }
    return result;
}
