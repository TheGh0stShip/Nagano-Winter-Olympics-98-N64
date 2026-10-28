typedef struct Record {
    unsigned char pad0[0x38];
    unsigned char color[0x100];
} Record;

extern unsigned char *D_80126BF0;
extern void func_8002FC74(unsigned char *color, int r, int g, int b);
extern void func_8002FB28(unsigned char *color, int r, int g, int b, int step, int count, int delay);

void func_80010654(short index) {
    int unused[5];
    Record *record = &((Record *)(D_80126BF0 + 0x842A0))[index];
    unsigned char *color = record->color;

    func_8002FC74(color, 0x80, 0x80, 0x80);
    func_8002FB28(color, 0xD0, 0xD0, 0xD0, -16, 5, 16);
}
