typedef struct SaveSlot {
    unsigned char data[0x7CC];
} SaveSlot;

extern SaveSlot *D_800730A8;
extern int func_80013E04(int arg0, int arg1, int offset, int size, SaveSlot *buffer);

short func_80040C00(unsigned char index, int arg1) {
    short result = 0;

    if (func_80013E04(0, arg1, index << 11, 0x800, D_800730A8[index].data)) {
        result = 1;
    }
    return result;
}
