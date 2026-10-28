typedef struct Entry {
    unsigned char pad[0x3C];
} Entry;

extern unsigned char *D_80126BF0;
extern short D_80135228[];

void func_8001385C(void) {
    short i;

    for (i = 0; i < 160; i++) {
        *(short *)((Entry *)(D_80126BF0 + 0x7D23C) + i) = 0;
        D_80135228[i] = 0;
    }
}
